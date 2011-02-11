#define STATICCONTENTEXCHANGE_SERVICEPEER_CC
#include "StaticContentExchange_ServicePeer.h"
#include "RequestMessage.h"
#include "Request.h"
#include "LruCache.h"
#include "LfuCache.h"
#include "MruCache.h"
#include "InterNodeRequestProtocol.h"
#include "TCP.h"
#include "UDP.h"
Define_Module(StaticContentExchange_ServicePeer)

void StaticContentExchange_ServicePeer::initialize(int stage){
	if(stage == 0){
		//No need to take care of cacheType since we have only LRU;
		this->_staticContentExchange_State = new StaticContentExchange_State();
		if(0 == strcmp(this->par("cacheType"), "LRU"))
				this->_staticContentExchange_State->setInformationSet(new LruCache(1024*1024*atof(par("cacheSizeInMbs")), par("cacheContents"), par("objectsReference"), par("shrink")));
		else if(0 == strcmp(this->par("cacheType"), "MRU"))
				this->_staticContentExchange_State->setInformationSet(new MruCache(1024*1024*atof(par("cacheSizeInMbs")), par("cacheContents"), par("objectsReference"), par("shrink")));
		else if(0 == strcmp(this->par("cacheType"), "LFU"))
						this->_staticContentExchange_State->setInformationSet(new LfuCache(1024*1024*atof(par("cacheSizeInMbs")), par("cacheContents"), par("objectsReference"), par("shrink")));
	}
	if(stage == 1){
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_ClientUnit")){
				this->_staticContentExchange_ClientUnit = (StaticContentExchange_ClientUnit*)iter();
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_ServerUnit")){
				this->_staticContentExchange_ServerUnit = (StaticContentExchange_ServerUnit*)iter();
				break;
			}
		}
		this->_staticContentExchange_State->setMaxDownloaders(getParentModule()->par("nDownloaders"));
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("tcp")){
				_staticContentExchange_State->setTCP ((TCP*)iter());
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("udp")){
				_staticContentExchange_State->setUDP ((UDP*)iter());
				break;
			}
		}
	}
}
int StaticContentExchange_ServicePeer::numInitStages() const{
	return 2;
}
void StaticContentExchange_ServicePeer::handleMessage(cMessage *msg){
	if(msg->arrivedOn("fromCDN_RequestsAssignerReceiverToClientUnit")){
		this->handleFromCDN_RequestsAssignerReceiverToClientUnitMessage(msg);
	}
	else if(msg->arrivedOn("fromCDN_RequestsAssignerReceiverToServerUnit")){
		this->handleFromCDN_RequestsAssignerReceiverToServerUnitMessage(msg);
	}
	else if(msg->arrivedOn("fromClientUnitOrServerUnit")){
		this->handleFromClientUnitOrServerUnitMessage(msg);
	}
}
void StaticContentExchange_ServicePeer::finish(){
}
void StaticContentExchange_ServicePeer::handleFromCDN_RequestsAssignerReceiverToClientUnitMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	encapuslateRequest_ProbagateCommand(this, originalRequest, this->gate("fromClientUnitOrServerUnit"), this->_staticContentExchange_ClientUnit->gate("fromServicePeer"));
}
void StaticContentExchange_ServicePeer::handleFromCDN_RequestsAssignerReceiverToServerUnitMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	encapuslateRequest_ProbagateCommand(this, originalRequest, this->gate("fromClientUnitOrServerUnit"), this->_staticContentExchange_ServerUnit->gate("fromServicePeer"));
}
void StaticContentExchange_ServicePeer::handleFromClientUnitOrServerUnitMessage(cMessage *msg){
	Request* echoRequest = ((RequestMessage*)msg)->detachRequest(); //detach the echo-request
	delete msg; msg = NULL; //now we can discard the incoming message
	decapsulateRequest_ProbagateEcho(this, &echoRequest);
}
StaticContentExchange_ServicePeer::~StaticContentExchange_ServicePeer(){
	delete this->_staticContentExchange_State;
}
StaticContentExchange_State* StaticContentExchange_ServicePeer::getState(){
	return this->_staticContentExchange_State;
}
