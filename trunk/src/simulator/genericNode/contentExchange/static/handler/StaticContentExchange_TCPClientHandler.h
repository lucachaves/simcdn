#ifndef STATICCONTENTEXCHANGE_TCPCLIENTHANDLER_H
#define STATICCONTENTEXCHANGE_TCPCLIENTHANDLER_H
#include "Handler.h"
#include "StaticContentExchange_State.h"

#include <omnetpp.h>
#include <TCPSocket.h>
#include <TCPSocketMap.h>
#include <DownloadersBase.h>
class DownloadersBase;
class StaticContentExchange_State;
class INET_API StaticContentExchange_TCPClientHandler :public Handler //FIXME must inherit also from Handler
{
protected:
	TCPSocket socket;
	TCPSocketMap socketMap;
	StaticContentExchange_State* _staticContentExchange_State;
	bool locked;
	TranspotType transportType;

protected:
	virtual void initialize(int stage);
	virtual void handleMessage(cMessage *msg);
	virtual void finish();
	int numInitStages() const;

public:
	void removeThread(DownloadersBase *thread);
	virtual TranspotType getTransportType();
	StaticContentExchange_TCPClientHandler();
	bool isLocked();
	void lock();
	void unlock();
     unsigned long long downloadedBytes;
};

#endif
