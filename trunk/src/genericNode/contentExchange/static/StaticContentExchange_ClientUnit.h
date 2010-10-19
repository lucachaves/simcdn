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
