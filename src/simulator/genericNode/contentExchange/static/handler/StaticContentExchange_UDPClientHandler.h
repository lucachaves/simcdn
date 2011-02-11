#ifndef STATICCONTENTEXCHANGE_UDPCLIENTHANDLER_H
#define STATICCONTENTEXCHANGE_UDPCLIENTHANDLER_H
#include "Handler.h"
#include "StaticContentExchange_State.h"
#include "IPvXAddress.h"
#include <omnetpp.h>

class StaticContentExchange_State;
class INET_API StaticContentExchange_UDPClientHandler :public Handler //FIXME must inherit also from Handler
{
protected:
	StaticContentExchange_State* _staticContentExchange_State;
	bool locked;
	TranspotType transportType;

protected:
	virtual void initialize(int stage);
	virtual void handleMessage(cMessage *msg);
	virtual void finish();
	int numInitStages() const;
    virtual void receiveStream(cPacket *msg);
    virtual void bindToPort(int port);
    virtual void sendToUDP(cPacket *msg, int srcPort, const IPvXAddress& destAddr, int destPort);
    virtual void printPacket(cPacket *msg);

public:
	StaticContentExchange_UDPClientHandler();
	virtual TranspotType getTransportType();
	bool isLocked();
	void lock();
	void unlock();
    unsigned long long downloadedBytes;
};

#endif
