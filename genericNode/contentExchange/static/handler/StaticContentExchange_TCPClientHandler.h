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
