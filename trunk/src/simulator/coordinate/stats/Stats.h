#ifndef STATS_H
#define STATS_H
#include <omnetpp.h>
#include "CacheLogEntry.h"
#include "RequestLogEntry.h"
class Stats : public cSimpleModule{
	protected:
		FILE* _statsFile;
		unsigned long long int totalRequests;
		unsigned long long int generatedRequests;
		unsigned long long int generatedRetries;
		unsigned long long int completedRequests;
		unsigned long long int failedRequests;

		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
	public:
		Stats();
		~Stats();
		void dumpString(char* str);
		void dumpCacheLogEntry(CacheLogEntry* cacheLogEntry);
		void dumpRequestLogEntry(RequestLogEntry* requestLogEntry);

		void addTotalRequests(unsigned long long int reqs);
		void incGeneratedRequests();
		void incGeneratedRetries();
		void incCompletedRequests();
		void incFailedRequests();
		void updateDisplay();
};
#endif

