#include "statistic.h"
#include <math.h>
#include <float.h>

namespace util {
	Statistic::Statistic() {
		this->fillNormalQuantileTable();
		this->min = DBL_MAX;
		this->max = DBL_MIN;
		this->sum = 0.0;
		this->confidenceLevel = 99.0;
		this->accuracy = 5.0f;
	}

	Statistic::~Statistic() {
		this->sample.erase(sample.begin(), sample.end());
		this->normalQuantileTable.clear();
	}

	// Adds an observation to the sample
	void Statistic::addObservation(double value) {
		this->sample.push_back(value);

		if (this->min > value)
			this->min = value;

		if (this->max < value)
			this->max = value;

		this->sum += value;
	}

	// Calculates the sample mean
	double Statistic::calculateMean() const {
		double mean = -1.0;
		int size = this->sample.size();

		if (size > 0)
			mean = this->sum / (double)size;

		return mean;
	}

	// Calculates the sample standard deviation
	double Statistic::calculateStandardDeviation() const {
		double stdDev;
		double summation = 0.0;
		double mean = this->calculateMean();
		int size = this->sample.size();

		if (size == 1)
			stdDev = 0.0;
		else {
			for (int i = 0; i < size; i++)
				summation += ((this->sample[i] - mean) * (this->sample[i] - mean));

			stdDev = sqrt((1.0 / (double)(size-1)) * summation);
		}

		return stdDev;
	}

	// Returns the confidence interval for the sample mean based
	// on the given confidence level
	double Statistic::calculateConfidenceInterval() const {
		double confidenceInterval;
		NQTable::const_iterator p1;
		double z;
		double alfa = 1.0 - (this->confidenceLevel / 100.0);
		double p = 1.0 - (alfa / 2.0);
		double stdDev = this->calculateStandardDeviation();
		int size = this->sample.size();

		// getting z value for p
		// (if p is not in the table, the closest value is used)
		p1 = this->normalQuantileTable.find(p);
		if (p1 == this->normalQuantileTable.end()) {
			if (p < 0.5)
				p = 0.5;
			else if (p > 0.9999)
				p = 0.9999;
			else if (p < 0.9)
				p = ((double) floor(100.0 * p)) / 100.0;
			else if (p > 0.999)
				p = ((double) floor(10000.0 * p)) / 10000.0;
			else
				p = ((double) floor(1000.0 * p)) / 1000.0;
		}

		/**
		 * I'm using find(p) instead of [p] because find(p) is const protected,
		 * while [p] isn't. This means that the value that I want is in
		 * find(p)->second, since find(p) will return a map iterator.
		 */
		z = this->normalQuantileTable.find(p)->second;
		confidenceInterval = z * stdDev / sqrt(size);

		return confidenceInterval;
	}

	// Calculates the precision of the confidence interval
	double Statistic::calculatePrecision() const {
		double precision = -1.0;
		double mean = this->calculateMean();
		double confidenceInterval = this->calculateConfidenceInterval();

		if (mean != 0)
			precision = 100.0 * confidenceInterval / mean;

		return precision;
	}

	// Calculates the number of replications required to achieve the
	// desired confidence level and accuracy
	int Statistic::calculateRequiredNumberOfReplications(double accuracy) {
		int rnReplications;
		NQTable::const_iterator p1;
		double z;
		double alfa = 1.0 - (this->confidenceLevel / 100.0);
		double p = 1.0 - (alfa / 2.0);
		double stdDev = this->calculateStandardDeviation();
		double mean = this->calculateMean();

		// getting z value for p
		// (if p is not in the table, the closest value is used)
		p1 = this->normalQuantileTable.find(p);
		if (p1 == this->normalQuantileTable.end()) {
			if (p < 0.5)
				p = 0.5;
			else if (p > 0.9999)
				p = 0.9999;
			else if (p < 0.9)
				p = ((double) floor(100.0 * p)) / 100.0;
			else if (p > 0.999)
				p = ((double) floor(10000.0 * p)) / 10000.0;
			else
				p = ((double) floor(1000.0 * p)) / 1000.0;
		}

		/**
		 * I'm using find(p) instead of [p] because find(p) is const protected,
		 * while [p] isn't. This means that the value that I want is in
		 * find(p)->second, since find(p) will return a map iterator.
		 */
		z = this->normalQuantileTable.find(p)->second;
		rnReplications = (int) ceil(((100.0 * z * stdDev) / (accuracy * mean)) * ((100.0 * z * stdDev) / (accuracy * mean)));

		return rnReplications;
	}

	// Fills in the Normal Quantile Table with the quantiles of
	// the Unit Normal Distribution
	void Statistic::fillNormalQuantileTable(void) {
		this->normalQuantileTable.insert(NQPair(0.5,0.0));
		this->normalQuantileTable.insert(NQPair(0.51,0.025));
		this->normalQuantileTable.insert(NQPair(0.52,0.050));
		this->normalQuantileTable.insert(NQPair(0.53,0.075));
		this->normalQuantileTable.insert(NQPair(0.54,0.100));
		this->normalQuantileTable.insert(NQPair(0.55,0.126));
		this->normalQuantileTable.insert(NQPair(0.56,0.151));
		this->normalQuantileTable.insert(NQPair(0.57,0.176));
		this->normalQuantileTable.insert(NQPair(0.58,0.202));
		this->normalQuantileTable.insert(NQPair(0.59,0.228));
		this->normalQuantileTable.insert(NQPair(0.6,0.253));
		this->normalQuantileTable.insert(NQPair(0.61,0.279));
		this->normalQuantileTable.insert(NQPair(0.62,0.305));
		this->normalQuantileTable.insert(NQPair(0.63,0.332));
		this->normalQuantileTable.insert(NQPair(0.64,0.358));
		this->normalQuantileTable.insert(NQPair(0.65,0.385));
		this->normalQuantileTable.insert(NQPair(0.66,0.412));
		this->normalQuantileTable.insert(NQPair(0.67,0.440));
		this->normalQuantileTable.insert(NQPair(0.68,0.468));
		this->normalQuantileTable.insert(NQPair(0.69,0.496));
		this->normalQuantileTable.insert(NQPair(0.7,0.524));
		this->normalQuantileTable.insert(NQPair(0.71,0.553));
		this->normalQuantileTable.insert(NQPair(0.72,0.583));
		this->normalQuantileTable.insert(NQPair(0.73,0.613));
		this->normalQuantileTable.insert(NQPair(0.74,0.643));
		this->normalQuantileTable.insert(NQPair(0.75,0.674));
		this->normalQuantileTable.insert(NQPair(0.76,0.706));
		this->normalQuantileTable.insert(NQPair(0.77,0.739));
		this->normalQuantileTable.insert(NQPair(0.78,0.772));
		this->normalQuantileTable.insert(NQPair(0.79,0.806));
		this->normalQuantileTable.insert(NQPair(0.8,0.842));
		this->normalQuantileTable.insert(NQPair(0.81,0.878));
		this->normalQuantileTable.insert(NQPair(0.82,0.915));
		this->normalQuantileTable.insert(NQPair(0.83,0.954));
		this->normalQuantileTable.insert(NQPair(0.84,0.994));
		this->normalQuantileTable.insert(NQPair(0.85,1.036));
		this->normalQuantileTable.insert(NQPair(0.86,1.080));
		this->normalQuantileTable.insert(NQPair(0.87,1.126));
		this->normalQuantileTable.insert(NQPair(0.88,1.175));
		this->normalQuantileTable.insert(NQPair(0.89,1.227));
		this->normalQuantileTable.insert(NQPair(0.9,1.282));
		this->normalQuantileTable.insert(NQPair(0.901,1.287));
		this->normalQuantileTable.insert(NQPair(0.902,1.293));
		this->normalQuantileTable.insert(NQPair(0.903,1.299));
		this->normalQuantileTable.insert(NQPair(0.904,1.305));
		this->normalQuantileTable.insert(NQPair(0.905,1.311));
		this->normalQuantileTable.insert(NQPair(0.906,1.317));
		this->normalQuantileTable.insert(NQPair(0.907,1.323));
		this->normalQuantileTable.insert(NQPair(0.908,1.329));
		this->normalQuantileTable.insert(NQPair(0.909,1.335));
		this->normalQuantileTable.insert(NQPair(0.91,1.341));
		this->normalQuantileTable.insert(NQPair(0.911,1.347));
		this->normalQuantileTable.insert(NQPair(0.912,1.353));
		this->normalQuantileTable.insert(NQPair(0.913,1.359));
		this->normalQuantileTable.insert(NQPair(0.914,1.366));
		this->normalQuantileTable.insert(NQPair(0.915,1.372));
		this->normalQuantileTable.insert(NQPair(0.916,1.379));
		this->normalQuantileTable.insert(NQPair(0.917,1.385));
		this->normalQuantileTable.insert(NQPair(0.918,1.392));
		this->normalQuantileTable.insert(NQPair(0.919,1.398));
		this->normalQuantileTable.insert(NQPair(0.92,1.405));
		this->normalQuantileTable.insert(NQPair(0.921,1.412));
		this->normalQuantileTable.insert(NQPair(0.922,1.419));
		this->normalQuantileTable.insert(NQPair(0.923,1.426));
		this->normalQuantileTable.insert(NQPair(0.924,1.433));
		this->normalQuantileTable.insert(NQPair(0.925,1.440));
		this->normalQuantileTable.insert(NQPair(0.926,1.447));
		this->normalQuantileTable.insert(NQPair(0.927,1.454));
		this->normalQuantileTable.insert(NQPair(0.928,1.461));
		this->normalQuantileTable.insert(NQPair(0.929,1.468));
		this->normalQuantileTable.insert(NQPair(0.93,1.476));
		this->normalQuantileTable.insert(NQPair(0.931,1.483));
		this->normalQuantileTable.insert(NQPair(0.932,1.491));
		this->normalQuantileTable.insert(NQPair(0.933,1.499));
		this->normalQuantileTable.insert(NQPair(0.934,1.506));
		this->normalQuantileTable.insert(NQPair(0.935,1.514));
		this->normalQuantileTable.insert(NQPair(0.936,1.522));
		this->normalQuantileTable.insert(NQPair(0.937,1.530));
		this->normalQuantileTable.insert(NQPair(0.938,1.538));
		this->normalQuantileTable.insert(NQPair(0.939,1.546));
		this->normalQuantileTable.insert(NQPair(0.94,1.555));
		this->normalQuantileTable.insert(NQPair(0.941,1.563));
		this->normalQuantileTable.insert(NQPair(0.942,1.572));
		this->normalQuantileTable.insert(NQPair(0.943,1.580));
		this->normalQuantileTable.insert(NQPair(0.944,1.589));
		this->normalQuantileTable.insert(NQPair(0.945,1.598));
		this->normalQuantileTable.insert(NQPair(0.946,1.607));
		this->normalQuantileTable.insert(NQPair(0.947,1.616));
		this->normalQuantileTable.insert(NQPair(0.948,1.626));
		this->normalQuantileTable.insert(NQPair(0.949,1.635));
		this->normalQuantileTable.insert(NQPair(0.95,1.645));
		this->normalQuantileTable.insert(NQPair(0.951,1.655));
		this->normalQuantileTable.insert(NQPair(0.952,1.665));
		this->normalQuantileTable.insert(NQPair(0.953,1.675));
		this->normalQuantileTable.insert(NQPair(0.954,1.685));
		this->normalQuantileTable.insert(NQPair(0.955,1.695));
		this->normalQuantileTable.insert(NQPair(0.956,1.706));
		this->normalQuantileTable.insert(NQPair(0.957,1.717));
		this->normalQuantileTable.insert(NQPair(0.958,1.728));
		this->normalQuantileTable.insert(NQPair(0.959,1.739));
		this->normalQuantileTable.insert(NQPair(0.96,1.751));
		this->normalQuantileTable.insert(NQPair(0.961,1.762));
		this->normalQuantileTable.insert(NQPair(0.962,1.774));
		this->normalQuantileTable.insert(NQPair(0.963,1.787));
		this->normalQuantileTable.insert(NQPair(0.964,1.799));
		this->normalQuantileTable.insert(NQPair(0.965,1.812));
		this->normalQuantileTable.insert(NQPair(0.966,1.825));
		this->normalQuantileTable.insert(NQPair(0.967,1.838));
		this->normalQuantileTable.insert(NQPair(0.968,1.852));
		this->normalQuantileTable.insert(NQPair(0.969,1.866));
		this->normalQuantileTable.insert(NQPair(0.97,1.881));
		this->normalQuantileTable.insert(NQPair(0.971,1.896));
		this->normalQuantileTable.insert(NQPair(0.972,1.911));
		this->normalQuantileTable.insert(NQPair(0.973,1.927));
		this->normalQuantileTable.insert(NQPair(0.974,1.943));
		this->normalQuantileTable.insert(NQPair(0.975,1.960));
		this->normalQuantileTable.insert(NQPair(0.976,1.977));
		this->normalQuantileTable.insert(NQPair(0.977,1.995));
		this->normalQuantileTable.insert(NQPair(0.978,2.014));
		this->normalQuantileTable.insert(NQPair(0.979,2.034));
		this->normalQuantileTable.insert(NQPair(0.98,2.054));
		this->normalQuantileTable.insert(NQPair(0.981,2.075));
		this->normalQuantileTable.insert(NQPair(0.982,2.097));
		this->normalQuantileTable.insert(NQPair(0.983,2.120));
		this->normalQuantileTable.insert(NQPair(0.984,2.144));
		this->normalQuantileTable.insert(NQPair(0.985,2.170));
		this->normalQuantileTable.insert(NQPair(0.986,2.197));
		this->normalQuantileTable.insert(NQPair(0.987,2.226));
		this->normalQuantileTable.insert(NQPair(0.988,2.257));
		this->normalQuantileTable.insert(NQPair(0.989,2.290));
		this->normalQuantileTable.insert(NQPair(0.99,2.326));
		this->normalQuantileTable.insert(NQPair(0.9901,2.330));
		this->normalQuantileTable.insert(NQPair(0.9902,2.334));
		this->normalQuantileTable.insert(NQPair(0.9903,2.338));
		this->normalQuantileTable.insert(NQPair(0.9904,2.342));
		this->normalQuantileTable.insert(NQPair(0.9905,2.346));
		this->normalQuantileTable.insert(NQPair(0.9906,2.349));
		this->normalQuantileTable.insert(NQPair(0.9907,2.353));
		this->normalQuantileTable.insert(NQPair(0.9908,2.357));
		this->normalQuantileTable.insert(NQPair(0.9909,2.362));
		this->normalQuantileTable.insert(NQPair(0.991,2.366));
		this->normalQuantileTable.insert(NQPair(0.9911,2.370));
		this->normalQuantileTable.insert(NQPair(0.9912,2.374));
		this->normalQuantileTable.insert(NQPair(0.9913,2.378));
		this->normalQuantileTable.insert(NQPair(0.9914,2.382));
		this->normalQuantileTable.insert(NQPair(0.9915,2.387));
		this->normalQuantileTable.insert(NQPair(0.9916,2.391));
		this->normalQuantileTable.insert(NQPair(0.9917,2.395));
		this->normalQuantileTable.insert(NQPair(0.9918,2.400));
		this->normalQuantileTable.insert(NQPair(0.9919,2.404));
		this->normalQuantileTable.insert(NQPair(0.992,2.409));
		this->normalQuantileTable.insert(NQPair(0.9921,2.414));
		this->normalQuantileTable.insert(NQPair(0.9922,2.418));
		this->normalQuantileTable.insert(NQPair(0.9923,2.423));
		this->normalQuantileTable.insert(NQPair(0.9924,2.428));
		this->normalQuantileTable.insert(NQPair(0.9925,2.432));
		this->normalQuantileTable.insert(NQPair(0.9926,2.437));
		this->normalQuantileTable.insert(NQPair(0.9927,2.442));
		this->normalQuantileTable.insert(NQPair(0.9928,2.447));
		this->normalQuantileTable.insert(NQPair(0.9929,2.452));
		this->normalQuantileTable.insert(NQPair(0.993,2.457));
		this->normalQuantileTable.insert(NQPair(0.9931,2.462));
		this->normalQuantileTable.insert(NQPair(0.9932,2.468));
		this->normalQuantileTable.insert(NQPair(0.9933,2.473));
		this->normalQuantileTable.insert(NQPair(0.9934,2.478));
		this->normalQuantileTable.insert(NQPair(0.9935,2.484));
		this->normalQuantileTable.insert(NQPair(0.9936,2.489));
		this->normalQuantileTable.insert(NQPair(0.9937,2.495));
		this->normalQuantileTable.insert(NQPair(0.9938,2.501));
		this->normalQuantileTable.insert(NQPair(0.9939,2.506));
		this->normalQuantileTable.insert(NQPair(0.994,2.512));
		this->normalQuantileTable.insert(NQPair(0.9941,2.518));
		this->normalQuantileTable.insert(NQPair(0.9942,2.524));
		this->normalQuantileTable.insert(NQPair(0.9943,2.530));
		this->normalQuantileTable.insert(NQPair(0.9944,2.536));
		this->normalQuantileTable.insert(NQPair(0.9945,2.543));
		this->normalQuantileTable.insert(NQPair(0.9946,2.549));
		this->normalQuantileTable.insert(NQPair(0.9947,2.556));
		this->normalQuantileTable.insert(NQPair(0.9948,2.562));
		this->normalQuantileTable.insert(NQPair(0.9949,2.569));
		this->normalQuantileTable.insert(NQPair(0.995,2.576));
		this->normalQuantileTable.insert(NQPair(0.9951,2.583));
		this->normalQuantileTable.insert(NQPair(0.9952,2.590));
		this->normalQuantileTable.insert(NQPair(0.9953,2.597));
		this->normalQuantileTable.insert(NQPair(0.9954,2.605));
		this->normalQuantileTable.insert(NQPair(0.9955,2.612));
		this->normalQuantileTable.insert(NQPair(0.9956,2.620));
		this->normalQuantileTable.insert(NQPair(0.9957,2.628));
		this->normalQuantileTable.insert(NQPair(0.9958,2.636));
		this->normalQuantileTable.insert(NQPair(0.9959,2.644));
		this->normalQuantileTable.insert(NQPair(0.996,2.652));
		this->normalQuantileTable.insert(NQPair(0.9961,2.661));
		this->normalQuantileTable.insert(NQPair(0.9962,2.669));
		this->normalQuantileTable.insert(NQPair(0.9963,2.678));
		this->normalQuantileTable.insert(NQPair(0.9964,2.687));
		this->normalQuantileTable.insert(NQPair(0.9965,2.697));
		this->normalQuantileTable.insert(NQPair(0.9966,2.706));
		this->normalQuantileTable.insert(NQPair(0.9967,2.716));
		this->normalQuantileTable.insert(NQPair(0.9968,2.727));
		this->normalQuantileTable.insert(NQPair(0.9969,2.737));
		this->normalQuantileTable.insert(NQPair(0.997,2.748));
		this->normalQuantileTable.insert(NQPair(0.9971,2.759));
		this->normalQuantileTable.insert(NQPair(0.9972,2.770));
		this->normalQuantileTable.insert(NQPair(0.9973,2.782));
		this->normalQuantileTable.insert(NQPair(0.9974,2.794));
		this->normalQuantileTable.insert(NQPair(0.9975,2.807));
		this->normalQuantileTable.insert(NQPair(0.9976,2.820));
		this->normalQuantileTable.insert(NQPair(0.9977,2.834));
		this->normalQuantileTable.insert(NQPair(0.9978,2.848));
		this->normalQuantileTable.insert(NQPair(0.9979,2.863));
		this->normalQuantileTable.insert(NQPair(0.998,2.878));
		this->normalQuantileTable.insert(NQPair(0.9981,2.894));
		this->normalQuantileTable.insert(NQPair(0.9982,2.911));
		this->normalQuantileTable.insert(NQPair(0.9983,2.929));
		this->normalQuantileTable.insert(NQPair(0.9984,2.948));
		this->normalQuantileTable.insert(NQPair(0.9985,2.968));
		this->normalQuantileTable.insert(NQPair(0.9986,2.989));
		this->normalQuantileTable.insert(NQPair(0.9987,3.011));
		this->normalQuantileTable.insert(NQPair(0.9988,3.036));
		this->normalQuantileTable.insert(NQPair(0.9989,3.062));
		this->normalQuantileTable.insert(NQPair(0.999,3.090));
		this->normalQuantileTable.insert(NQPair(0.9991,3.121));
		this->normalQuantileTable.insert(NQPair(0.9992,3.156));
		this->normalQuantileTable.insert(NQPair(0.9993,3.195));
		this->normalQuantileTable.insert(NQPair(0.9994,3.239));
		this->normalQuantileTable.insert(NQPair(0.9995,3.291));
		this->normalQuantileTable.insert(NQPair(0.9996,3.353));
		this->normalQuantileTable.insert(NQPair(0.9997,3.432));
		this->normalQuantileTable.insert(NQPair(0.9998,3.540));
		this->normalQuantileTable.insert(NQPair(0.9999,3.719));
	}
};
