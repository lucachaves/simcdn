#ifndef CDN_REQUESTSASSIGNERRECEIVER_H
#define CDN_REQUESTSASSIGNERRECEIVER_H
#include "CDN_Commands.h"
#include "RequestsAssignerReceiver.h"
#include "StaticContentExchange_ServicePeer.h"
#include "Stats.h"
#include "StaticContentExchange_State.h"
class StaticContentExchange_ServicePeer;
class StaticContentExchange_State;
class CDN_RequestsAssignerReceiver : public RequestsAssignerReceiver{
	protected:
		int nRetries;
		double mean;
		Stats* _stats;
		const char* commandsScriptFilename;
		CDN_Commands* _commands;
		StaticContentExchange_ServicePeer* _staticContentExchange_ServicePeer;
		cMessage* _marchEvent;

		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();

		void handleSelfMessage(cMessage *msg);
		void handleFromNegotiatorMessage(cMessage *msg);
		void handleFromCentralUnitMessage(cMessage *msg);
		void handleFromServicePeerMessage(cMessage *msg);
		void handleFromRetry(cMessage *msg);
		void scheduleNextCommand();
		void prepareRequestForRetry(Request* request);
	public:
		CDN_RequestsAssignerReceiver();
		~CDN_RequestsAssignerReceiver();
		StaticContentExchange_State* getStaticContentExchangeState();
};
#endif
