#ifndef _STATISTIC_H_
#define _STATISTIC_H_

#include <vector>
#include <map>
using namespace std;

namespace util {
typedef map <double,double> NQTable;
typedef pair <double,double> NQPair;

// This class defines methods to provide statistics about samples
	class Statistic {
		private:
			double min;
			double max;
			double sum;
			double confidenceLevel;
			double accuracy;
			vector<double> sample;
			NQTable normalQuantileTable;

			double calculateMean() const ;
			double calculateStandardDeviation() const;
			double calculateConfidenceInterval() const;
			double calculatePrecision() const;
			int calculateRequiredNumberOfReplications(double accuracy);
			void fillNormalQuantileTable();

		public:
			Statistic();
			~Statistic();

			void addObservation(double value);

			// This method returns the sample size
			// (i.e., the number of observations within the sample)
			int getSampleSize() const {
				return this->sample.size();
			}

			// Returns the minimal observation of the sample
			double getSampleMin() const {
				return this->min;
			}

			// Returns the maximal observation of the sample
			double getSampleMax() const {
				return this->max;
			}

			// Returns the sample mean
			double getSampleMean() const {
				return this->calculateMean();
			}

			// Returns the sample standard deviation
			double getSampleStandardDeviation() const {
				return this->calculateStandardDeviation();
			}

			// Returns the confidence interval for the sample mean based
			// on the default confidence level
			double getConfidenceInterval() const {
				return this->calculateConfidenceInterval();
			}

			// Returns the precision of the default confidence interval
			double getPrecision() const {
				return this->calculatePrecision();
			}

			// Returns the number of replications required to achieve the 
			// desired confidence level and accuracy
			int getRequiredNumberOfReplications(double accuracy) {
				return this->calculateRequiredNumberOfReplications(accuracy);
			}
			
			int getRequiredNumberOfReplications() {
				return this->calculateRequiredNumberOfReplications(this->accuracy);
			}

			//Returns the confidence level
			double getConfidenceLevel() const {
				return this->confidenceLevel;
			}
			
			//Returns a sample by his index
			double getSampleByIndex(int index) const {
				return this->sample[index];
			}
			
			// Sets the confidence level value
			void setConfidenceLevel(double confidenceLevel) {
				this->confidenceLevel = confidenceLevel;
			}
			
			void setAccuracy(double accuracy) {
				this->accuracy = accuracy;
			}
			
			double getAccuracy() const {
				return this->accuracy;
			}

			// Resets the sample (i.e., deletes all the observations of the sample)
			void resetSample() {
				sample.erase(sample.begin(), sample.end());
			}
	};
};

#endif
