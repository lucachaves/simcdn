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

#ifndef STATICCONTENTEXCHANGE_ALTERNATESERVERDETECTOR_H
#define STATICCONTENTEXCHANGE_ALTERNATESERVERDETECTOR_H
#include "AlternateServerDetector.h"
#include "CDN_CentralUnit.h"
class CDN_CentralUnit;
class StaticContentExchange_AlternateServerDetector : public AlternateServerDetector{
	protected:
		CDN_CentralUnit* _cdn_CentralUnit;

		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
		void handleFromClientUnitMessage(cMessage *msg);
		void handleFromCentralUnitMessage(cMessage *msg);
};
#endif
