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

#ifndef CDN_CENTRALUNIT_H
#define CDN_CENTRALUNIT_H
#include "CentralUnit.h"
#include <vector>
#include <map>
#include "CDN_RequestsAssignerReceiver.h"
#include <boost/pool/pool_alloc.hpp>
class CDN_RequestsAssignerReceiver;
using namespace std;
class CDN_CentralUnit : public CentralUnit{
	protected:
		cTopology _topology;
		vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<CDN_RequestsAssignerReceiver*> > _availableSurrogateServers;
		vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<CDN_RequestsAssignerReceiver*> > _availableOriginServers;
		vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<CDN_RequestsAssignerReceiver*> > _availableClients;

		double** _surrogateToSurrogateDistance;
		double** _originToSurrogateDistance;
		double** _surrogateToClientDistance;

		double startTime;

		map<int, int> _surrogateIdToIndex;
		map<int, int> _originIdToIndex;
		map<int, int> _clientIdToIndex;

		map<int, int> _closestOriginToSurrogate;
		map<int, int> _closestSurrogateToClient;

		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
		void handleFromAlternateServerDetectorMessage(cMessage *msg);
		void handleSelfMessage(cMessage *msg);
		cGate* getCooperativeAlternateServerGate(int requestedObjectId, cModule *client);
		cGate* getCooperativeAlternateServerGateDistributed(int requestedObjectId, cModule *client);
		cGate* getNonCooperativeAlternateServerGate(int requestedObjectId, cModule *client);
		cGate* getRandomAlternateServerGate(int requestedObjectId, cModule *client);
	cGate* getLoadBalanceAlternateServerGate(int requestedObjectId, cModule *client);
	public:
		void registerSurrogateServer(CDN_RequestsAssignerReceiver* surrogateServer);
		void registerOriginServer(CDN_RequestsAssignerReceiver* originServer);
		void registerClient(CDN_RequestsAssignerReceiver* client);
		void distributeContentInSurrogate();
		vector<int> loadScript(const char* script);
		~CDN_CentralUnit();
};
#endif
