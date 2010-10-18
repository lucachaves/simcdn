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

#ifndef CDN_COMMANDS_H
#define CDN_COMMANDS_H
#include "StaticContentExchange_ServicePeerCommand.h"
#include "Commands.h"
#include <vector>
#include <boost/pool/pool_alloc.hpp>
using namespace std;
class CDN_Commands : public Commands {
	private:
		vector<StaticContentExchange_ServicePeerCommand*, boost::pool_allocator<StaticContentExchange_ServicePeerCommand*> > _commands; // .back() is the command with the lowest timestamp
	public:
		void insertCommandByTime(StaticContentExchange_ServicePeerCommand* StaticContentExchange_ServicePeerCommand);
		~CDN_Commands();
		void loadScript(const char* script, const char* generiNodeType);
		double getGetNextCommandTime();
		StaticContentExchange_ServicePeerCommand* detachNextCommand();
		int getNumberOfCommands(){return _commands.size();};
};
#endif
