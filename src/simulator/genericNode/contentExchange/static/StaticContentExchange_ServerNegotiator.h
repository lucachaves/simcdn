#ifndef STATICCONTENTEXCHANGE_SERVERNEGOTIATOR_H
#define STATICCONTENTEXCHANGE_SERVERNEGOTIATOR_H
#include "Negotiator.h"
#include "StaticContentExchange_State.h"
class StaticContentExchange_State;
class StaticContentExchange_ServerNegotiator : public Negotiator{
	protected:
		StaticContentExchange_State* _staticContentExchange_State;
		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void handleFromServerUnitMessage(cMessage *msg);
		void handleFromServerHandlerMessage(cMessage *msg);
		void finish();
};
#endif
