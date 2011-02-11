#ifndef STATICCONTENTEXCHANGE_TCPSERVERHANDLER_H
#define STATICCONTENTEXCHANGE_TCPSERVERHANDLER_H
#include "Handler.h"
#include "StaticContentExchange_State.h"
#include "StaticContentExchange_ServerUnit.h"
#include "StaticObject.h"
#include <omnetpp.h>
#include <TCPSocket.h>
#include <TCPSocketMap.h>
#include <DownloadersBase.h>
#include "Request.h"
class Request;
class StaticContentExchange_State;
class StaticContentExchange_ServerUnit;
class INET_API StaticContentExchange_TCPServerHandler :public Handler, public TCPSocket::CallbackInterface //FIXME must inherit also from Handler
{
protected:
	StaticObject* currentObject;
	Request* currentRequest;
	bool locked;
	StaticContentExchange_State* _staticContentExchange_State;
     StaticContentExchange_ServerUnit* _staticContentExchange_ServerUnit;
     TranspotType transportType;
	TCPSocket socket;


protected:
	virtual void initialize(int stage);
	virtual void handleMessage(cMessage *msg);
	virtual void finish();
	int numInitStages() const;

	virtual void socketDataArrived(int, void *, cPacket *msg, bool urgent);
	virtual void socketEstablished(int, void *);
	virtual void socketPeerClosed(int, void *);
	virtual void socketClosed(int, void *);
	virtual void socketFailure(int, void *, int code);
	virtual void socketStatusArrived(int, void *, TCPStatusInfo *status);
	void transmitObject();

public:
	StaticContentExchange_TCPServerHandler();
	virtual TranspotType getTransportType();
	virtual bool isLocked();
	void lock();
	void unlock();
};

#endif
