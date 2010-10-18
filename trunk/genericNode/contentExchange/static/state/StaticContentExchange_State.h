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

#ifndef STATICCONTENTEXCHANGE_STATE_H
#define STATICCONTENTEXCHANGE_STATE_H
#include "State.h"
#include "Cache.h"
#include "InformationSet.h"
#include "Handler.h"
#include <vector>
#include <boost/pool/pool_alloc.hpp>
#include "TCP.h"
#include "UDP.h"
#include "StaticContentExchange_ServicePeerCommand.h"
class Handler;
using namespace std;
class StaticContentExchange_State : public State{
	private:
		Cache* _cache;
		vector<Handler*, boost::pool_allocator<Handler*> > _clientHandlers;
		vector<Handler*, boost::pool_allocator<Handler*> > _serverHandlers;
		int _reservedDonwloaders;
		int _maxDowloaders;
		TCP* tcp;
		UDP* udp;
	public:
		StaticContentExchange_State();
		~StaticContentExchange_State();
		Cache* getCache();
		void setCache( Cache* cache );

		//by InformationSet we mean LruCache
		InformationSet* getInformationSet();
		void setInformationSet(InformationSet* informationSet);
		void registerClientHandler(Handler* handler);
		void registerServerHandler(Handler* handler);
		bool thereIsClientHandlerAvailable();
		bool thereIsServerHandlerAvailable();

		Handler* getAvailableClientHandler(TranspotType transportType);
		Handler* getClientHandler(int port);
		Handler* getAvailableServerHandler(TranspotType transportType);

		void setMaxDownloaders(int maxDowloaders);
		void reserveDownloader();
		void freeDownloader();
		double uploadLoad();
		bool hasAvailableEphemeralPorts(TranspotType transportType);
		void setTCP(TCP* theTCP){tcp = theTCP;}
		void setUDP(UDP* theUDP){udp = theUDP;}
};
#endif
