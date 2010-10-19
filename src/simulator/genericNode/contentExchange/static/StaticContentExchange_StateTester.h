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
