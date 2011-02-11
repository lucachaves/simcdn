#ifndef STATICCONTENTEXCHANGE_SERVICEPEER_H
#define STATICCONTENTEXCHANGE_SERVICEPEER_H
#include "ServicePeer.h"
#include "StaticContentExchange_ClientUnit.h"
#include "StaticContentExchange_ServerUnit.h"
#include "StaticContentExchange_State.h"
class StaticContentExchange_ClientUnit;
class StaticContentExchange_ServerUnit;
class StaticContentExchange_ServicePeer : public ServicePeer{
	protected:
		StaticContentExchange_ClientUnit* _staticContentExchange_ClientUnit;
		StaticContentExchange_ServerUnit* _staticContentExchange_ServerUnit;

		StaticContentExchange_State* _staticContentExchange_State;

		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
		void handleFromCDN_RequestsAssignerReceiverToServerUnitMessage(cMessage *msg);
		void handleFromCDN_RequestsAssignerReceiverToClientUnitMessage(cMessage *msg);
		void handleFromClientUnitOrServerUnitMessage(cMessage *msg);
	public:
		~StaticContentExchange_ServicePeer();
		StaticContentExchange_State* getState();
};
#endif
