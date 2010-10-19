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
