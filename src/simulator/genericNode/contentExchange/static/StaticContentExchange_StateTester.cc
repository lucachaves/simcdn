#define STATICCONTENTEXCHANGE_STATETESTER_CC
#include "StaticContentExchange_StateTester.h"
#include "RequestMessage.h"
#include "Request.h"
#include "StaticContentExchange_ServicePeerCommand.h"
#include "Cache.h"
#include <assert.h>
Define_Module(StaticContentExchange_StateTester);
void StaticContentExchange_StateTester::processRequest(Request* request){
}
void StaticContentExchange_StateTester::replyRequest(Request* request){
}

void StaticContentExchange_StateTester::initialize(int stage){
	if(stage == 0){

	}
	if(stage == 1){
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_ServicePeer")){
				this->_staticContentExchange_ServicePeer = (StaticContentExchange_ServicePeer*)iter();
				break;
			}
		}
		this->_staticContentExchange_State = this->_staticContentExchange_ServicePeer->getState();

	}
}
int StaticContentExchange_StateTester::numInitStages() const{
	return 2;
}
void StaticContentExchange_StateTester::handleMessage(cMessage *msg){
	Request* request = ((RequestMessage*)msg)->getRequest(); //recieve the request

	Cache* cache = (Cache*)this->_staticContentExchange_State->getInformationSet();
	if(cache->objectExists(((StaticContentExchange_ServicePeerCommand*)request->getCommand())->getObjectId())){
		request->setStatus(OK);
	}
	else{
		request->setStatus(FAILED);
	}
	sendDirect(msg, 0, 0, request->getReplyGate());
}
void StaticContentExchange_StateTester::finish(){
}
void StaticContentExchange_StateTester::setState(StaticContentExchange_State* staticContentExchange_State){
	assert(staticContentExchange_State);
	this->_staticContentExchange_State = staticContentExchange_State;
}
StaticContentExchange_StateTester::StaticContentExchange_StateTester(){
};

