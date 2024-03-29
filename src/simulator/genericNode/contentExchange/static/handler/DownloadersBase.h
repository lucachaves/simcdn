#ifndef DOWNLOADERSBASE_H
#define DOWNLOADERSBASE_H

#include <omnetpp.h>
#include "TCPSocket.h"
#include "TCPSocketMap.h"
#include "StaticContentExchange_TCPClientHandler.h"
#include "StaticContentExchange_State.h"

class StaticContentExchange_TCPClientHandler;
class StaticContentExchange_State;
class INET_API DownloadersBase : public cPolymorphic, public TCPSocket::CallbackInterface
{
private:
// 	bool data_arrived;
	StaticContentExchange_TCPClientHandler *hostmod;
	TCPSocket *sock; // ptr into socketMap managed by TCPSrvHostApp
	StaticContentExchange_State* _staticContentExchange_State;
protected:
    // internal: TCPSocket::CallbackInterface methods
	virtual void socketDataArrived(int, void *, cPacket *msg, bool urgent);
	virtual void socketEstablished(int, void *);
	virtual void socketPeerClosed(int, void *);
	virtual void socketClosed(int, void *);
	virtual void socketFailure(int, void *, int code);
	virtual void socketStatusArrived(int, void *, TCPStatusInfo *status);

public:
	// internal: called by StaticContentExchange_ClientHandler after creating this module
	void setup(StaticContentExchange_TCPClientHandler *hostmodule, TCPSocket *socket, StaticContentExchange_State* staticContentExchange_State);
	DownloadersBase();
	~DownloadersBase();

    /** Returns the socket object */
	TCPSocket *socket();

    /** Returns pointer to the host module */
	StaticContentExchange_TCPClientHandler *hostModule();

    /**
     * Schedule an event. Do not use getContextPointer() of cMessage, because
     * DownloadersBase uses it for its own purposes.
     */
	void scheduleAt(simtime_t t, cMessage *msg);

    /** Cancel an event */
	void cancelEvent(cMessage *msg);

    /** Returns simulation time */
	simtime_t simTime();

    /** @name Callback methods, called on different socket events. */
    //@{
    /**
     * Called when connection is established.
     */
	void established();

    /**
     * Called when a data packet arrives.
     */
	void dataArrived(cPacket *msg, bool urgent);

    /**
     * Called when a timer (scheduled via scheduleAt()) expires.
     */
	void timerExpired(cMessage *timer);

    /**
     * Called when the client closes the connection.
     */
	void peerClosed();

    /**
     * Called when the connection closes (successful TCP teardown).
     */
	void closed();

    /**
     * Called when the connection breaks (TCP error).
     */
	void failure(int code);

    /**
     * Called when a status arrives in response to socket()->status().
     */
	void statusArrived(TCPStatusInfo *status);
    //@}
};
#endif
