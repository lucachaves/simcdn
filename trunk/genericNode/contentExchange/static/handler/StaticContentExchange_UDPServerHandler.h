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

#ifndef STATICCONTENTEXCHANGE_UDPSERVERHANDLER_H
#define STATICCONTENTEXCHANGE_UDPSERVERHANDLER_H
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
class INET_API StaticContentExchange_UDPServerHandler :public Handler//FIXME must inherit also from Handler
{
protected:
	StaticObject* currentObject;
	Request* currentRequest;
	bool locked;
	StaticContentExchange_State* _staticContentExchange_State;
    StaticContentExchange_ServerUnit* _staticContentExchange_ServerUnit;
	TranspotType transportType;
	// statistics
	unsigned int numStreams;  // number of video streams served


protected:
	virtual void initialize(int stage);
	virtual void handleMessage(cMessage *msg);
	virtual void finish();
	int numInitStages() const;
    virtual void bindToPort(int port);
    virtual void sendToUDP(cPacket *msg, int srcPort, const IPvXAddress& destAddr, int destPort);
    virtual void printPacket(cPacket *msg);
    virtual void processStreamRequest(cMessage *msg);
	virtual void sendStreamData(cMessage *timer);

public:
	StaticContentExchange_UDPServerHandler();
	~StaticContentExchange_UDPServerHandler();
	virtual TranspotType getTransportType();
	virtual bool isLocked();
	void lock();
	void unlock();
};

#endif
