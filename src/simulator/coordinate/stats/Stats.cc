#define STATS_CC
#include "Stats.h"
Define_Module(Stats)
;
using namespace std;
void Stats::initialize(int stage) {
	if (stage == 0) {
		this->_statsFile = fopen(par("statsFile"), "w");
		if (!this->_statsFile) {
			throw cRuntimeError(
					"Unable to read file <%s> (line: %d, file: %s)",
					_statsFile, __LINE__, __FILE__);
				}
			}
		}
int Stats::numInitStages() const {
	return 1;
}
void Stats::handleMessage(cMessage *msg) {
}
void Stats::finish() {
	fflush(this->_statsFile);
}
Stats::Stats() {
	totalRequests = 0;
	generatedRequests = 0;
	generatedRetries = 0;
	completedRequests = 0;
	failedRequests = 0;
}
Stats::~Stats() {
	fclose(this->_statsFile);
	this->_statsFile = NULL;
}
void Stats::dumpString(char* str) {
	fprintf(this->_statsFile, "%s\n", str);
}
void Stats::dumpCacheLogEntry(CacheLogEntry* cacheLogEntry) {
	fprintf(this->_statsFile, "%lf,", cacheLogEntry->getTimeStamp());
	if (cacheLogEntry->getInitiator() == SURROGATE) {
		fprintf(this->_statsFile, "%s,", "SURROGATE");
	}
	if (cacheLogEntry->getInitiator() == ORIGIN) {
		fprintf(this->_statsFile, "%s,", "ORIGIN");
	}
	fprintf(this->_statsFile, "%s,", cacheLogEntry->getServerName()->c_str());
	if (cacheLogEntry->getCacheStatus() == HIT) {
		fprintf(this->_statsFile, "%s,", "HIT");
	}
	if (cacheLogEntry->getCacheStatus() == MISS) {
		fprintf(this->_statsFile, "%s,", "MISS");
	}
	fprintf(this->_statsFile, "%d\n", cacheLogEntry->getObjectId());
}
void Stats::dumpRequestLogEntry(RequestLogEntry* requestLogEntry) {
	if (requestLogEntry->getStatus() == ABORTED) {
		fprintf(this->_statsFile, "%s,", "ABORTED");
	}
	if (requestLogEntry->getStatus() == COMPLETED) {
		fprintf(this->_statsFile, "%s,", "COMPLETED");
	}
	if (requestLogEntry->getInitiator() == SURROGATE) {
		fprintf(this->_statsFile, "%s,", "SURROGATE");
	}
	if (requestLogEntry->getInitiator() == ORIGIN) {
		fprintf(this->_statsFile, "%s,", "ORIGIN");
	}
	if (requestLogEntry->getInitiator() == CLIENT) {
		fprintf(this->_statsFile, "%s,", "CLIENT");
	}
	fprintf(this->_statsFile, "%s,",
			requestLogEntry->getRequesterName()->c_str());
	fprintf(this->_statsFile, "%d,", requestLogEntry->getObjectId());
	fprintf(this->_statsFile, "%d,", requestLogEntry->getRetries());
	fprintf(this->_statsFile, "%lf,", requestLogEntry->getRequestStartTime());
	fprintf(this->_statsFile, "%lf,", requestLogEntry->getRequestEndTime());
	if (requestLogEntry->getWhy()) {
		fprintf(this->_statsFile, "%s\n", requestLogEntry->getWhy()->c_str());
	} else {
		fprintf(this->_statsFile, "%s\n", "-");
	}
}
void Stats::addTotalRequests(unsigned long long int reqs) {
	totalRequests += reqs;
}
void Stats::incGeneratedRequests() {
	generatedRequests++;
	updateDisplay();
}
void Stats::incGeneratedRetries() {
	generatedRetries++;
	updateDisplay();
}
void Stats::incCompletedRequests() {
	completedRequests++;
	updateDisplay();
}
void Stats::incFailedRequests() {
	failedRequests++;
	updateDisplay();
}
void Stats::updateDisplay() {
	if (generatedRequests % 5000 != 0) { //display ever 5000 requests
		return;
	}
	cout << "===================================================" << endl;
	cout << "Generated requests: " << generatedRequests << "/" << totalRequests
			<< endl;
	cout << "Completed requests: " << completedRequests << "/" << totalRequests
			<< endl;
	cout << "Failed requests: " << failedRequests << "/" << totalRequests
			<< endl;
	cout << "Retries: " << generatedRetries << endl;
	cout << "===================================================" << endl;
}
