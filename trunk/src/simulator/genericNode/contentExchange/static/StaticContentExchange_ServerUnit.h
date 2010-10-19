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
