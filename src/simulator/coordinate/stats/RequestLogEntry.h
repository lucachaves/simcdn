#ifndef REQUESTLOGENTRY_H
#define REQUESTLOGENTRY_H
#include "LogEntry.h"
#include <string>
enum Status{COMPLETED, ABORTED};
class RequestLogEntry : public LogEntry{
private:
	std::string* _requesterName;
	Initiator _initiator;
	int _objectId;
	int _retries;
	Status _status;
	double _requestStartTime;
	double _requestEndTime;
	std::string* _why;
public:
	std::string* getRequesterName();
	Initiator getInitiator();
	int getObjectId();
	double getHandshakeStartTime();
	double getHandshakeEndTime();
	int getRetries();
	
	Status getStatus();

	double getRequestStartTime();
	double getRequestEndTime();
	std::string* getWhy();

	//at creation time
	void setRequesterName(std::string* requesterName);
	void setInitiator(Initiator initiator);
	void setObjectId(int objectId);
	void setRequestStartTime(double requestStartTime);




	//called upon a failure
	void setWhy(std::string* who, std::string* when, std::string* why);
	void setWhyRaw(std::string* why);



	//called at the end
	void setRequestEndTime(double requestEndTime);
	void setStatus(Status status);
	void incRetries();//call it before a retry
	//void destroyWhy(); call before retry

	RequestLogEntry();
	~RequestLogEntry();
	void destroyWhy();

};
#endif
