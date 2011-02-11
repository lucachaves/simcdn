#ifndef HANDLER_H
#define HANDLER_H
#include <omnetpp.h>
#include "Request.h"
//class StaticContentExchange_State;
class Handler : public cSimpleModule{
//Deve ter param port
public:
	Handler();
	~Handler();
public:
	virtual bool isLocked();
	virtual void unlock();
	virtual void lock();
	virtual TranspotType getTransportType();
};
#endif
