#ifndef STATICCONTENTEXCHANGE_CLIENTNEGOTIATOR_H
#define STATICCONTENTEXCHANGE_CLIENTNEGOTIATOR_H
#include "Negotiator.h"
#include "StaticContentExchange_State.h"
class StaticContentExchange_ClientNegotiator : public Negotiator{
	protected:
		StaticContentExchange_State* _staticContentExchange_State;
		vector<Request*> _originalRequest;
		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
		void handleFromClientUnitMessage(cMessage *msg);
		void handleFromRequestsReceiverAssignerMessage(cMessage *msg);
		void handleFromUDPClient(cMessage *msg);
};
#endif
