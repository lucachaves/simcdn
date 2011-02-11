#ifndef CACHELOGENTRY_H
#define CACHELOGENTRY_H
#include "LogEntry.h"
#include <string>
enum CacheStatus{HIT, MISS};
class CacheLogEntry : public LogEntry{
private:
	Initiator _initiator;
	CacheStatus _cacheStatus;
	int _objectId;
	double _timeStamp;
	std::string* _serverName;

public:
	Initiator getInitiator();
	CacheStatus getCacheStatus();

	int getObjectId();
	double getTimeStamp();
	std::string*  getServerName();

	void setInitiator(Initiator initiator);
	void setCacheStatus(CacheStatus cacheStatus);

	void setObjectId(int objectId);
	void setTimeStamp(double timeStamp);
	void setServerName(std::string* serverName); //copies
	CacheLogEntry();
	~CacheLogEntry();
};
#endif
