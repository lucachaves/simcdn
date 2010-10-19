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
