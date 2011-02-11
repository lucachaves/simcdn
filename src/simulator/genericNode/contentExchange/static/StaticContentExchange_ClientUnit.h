#ifndef STATICCONTENTEXCHANGE_CLIENTUNIT_H
#define STATICCONTENTEXCHANGE_CLIENTUNIT_H
#include "ClientUnit.h"
#include "StaticContentExchange_StateTester.h"
#include "StaticContentExchange_AlternateServerDetector.h"
#include "StaticContentExchange_ClientNegotiator.h"
class StaticContentExchange_ClientNegotiator;
class StaticContentExchange_StateTester;
class StaticContentExchange_AlternateServerDetector;
class StaticContentExchange_ClientUnit : public ClientUnit{
	protected:
		StaticContentExchange_StateTester* _staticContentExchange_StateTester;
		StaticContentExchange_AlternateServerDetector* _alternateServerDetector;
		StaticContentExchange_ClientNegotiator* _staticContentExchange_ClientNegotiator;
		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
		void handleFromServicePeerMessage(cMessage *msg);
		void handleFromStateTesterMessage(cMessage *msg);
		void handleFromAlternateServerDetectorMessage(cMessage *msg);
		void handleFromServerUnitMessage(cMessage *msg);
		void handleFromNegotiatorMessage(cMessage *msg);
};
#endif
