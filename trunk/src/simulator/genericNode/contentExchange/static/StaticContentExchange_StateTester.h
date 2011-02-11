#ifndef STATICCONTENTEXCHANGE_STATETESTER_H
#define STATICCONTENTEXCHANGE_STATETESTER_H
#include <omnetpp.h>
#include "Request.h"
#include "StaticContentExchange_State.h"
#include "StateTester.h"
#include "StaticContentExchange_ServicePeer.h"

class StaticContentExchange_ServicePeer;
class StaticContentExchange_StateTester : public StateTester{
	protected:
		StaticContentExchange_State* _staticContentExchange_State;
		StaticContentExchange_ServicePeer* _staticContentExchange_ServicePeer;
		void processRequest(Request* request);
		void replyRequest(Request* request);

		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
	public:
		StaticContentExchange_StateTester();
		void setState(StaticContentExchange_State* staticContentExchange_State); //must be called only once

};

#endif
