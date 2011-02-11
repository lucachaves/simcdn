#ifndef STATICCONTENTEXCHANGE_SERVERUNIT_H
#define STATICCONTENTEXCHANGE_SERVERUNIT_H
#include "ServerUnit.h"
#include "StaticContentExchange_StateTester.h"
#include "StaticContentExchange_ServerNegotiator.h"
#include "StaticContentExchange_ClientUnit.h"
#include "Stats.h"
class StaticContentExchange_ClientUnit;
class StaticContentExchange_StateTester;
class StaticContentExchange_ServerNegotiator;
class StaticContentExchange_ServerUnit : public ServerUnit{
	protected:
		Stats* _stats;
		StaticContentExchange_StateTester* _staticContentExchange_StateTester;
		StaticContentExchange_ServerNegotiator* _staticContentExchange_ServerNegotiator;
		StaticContentExchange_ClientUnit* _staticContentExchange_ClientUnit;
		vector<Request*> requests; //Luiz - Store Request
		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void handleFromServicePeerMessage(cMessage *msg);
		void handleFromStateTesterMessage(cMessage* msg);
		void handleFromNegotiatorMessage(cMessage* msg);
		void handleFromClientUnitMessage(cMessage* msg);
		void finish();
     public:
          StaticContentExchange_ServerUnit();
          unsigned long long uploadedBytes;
};
#endif
