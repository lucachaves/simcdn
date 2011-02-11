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
