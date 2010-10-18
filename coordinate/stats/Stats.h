    //This file is part of CDNsim.

    //CDNsim is free software; you can redistribute it and/or modify
    //it under the terms of the GNU General Public License as published by
    //the Free Software Foundation; either version 2 of the License, or
    //(at your option) any later version.

    //CDNsim is distributed in the hope that it will be useful,
    //but WITHOUT ANY WARRANTY; without even the implied warranty of
    //MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    //GNU General Public License for more details.

    //You should have received a copy of the GNU General Public License
    //along with CDNsim; if not, write to the Free Software
    //Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

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

