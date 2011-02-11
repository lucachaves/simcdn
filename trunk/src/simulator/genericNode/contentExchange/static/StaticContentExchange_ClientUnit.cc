#define STATICCONTENTEXCHANGE_CLIENTUNIT_CC
#include "StaticContentExchange_ClientUnit.h"
#include "Request.h"
#include "RequestMessage.h"
#include "StaticContentExchange_ServicePeerCommand.h"
#include "CDN_CentralUnit_Reply.h"
#include "InterNodeRequestProtocol.h"

Define_Module(StaticContentExchange_ClientUnit);

void StaticContentExchange_ClientUnit::initialize(int stage){
	if(stage == 0){
	}
	if(stage == 1){
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_StateTester")){
				this->_staticContentExchange_StateTester = (StaticContentExchange_StateTester*)iter();
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_AlternateServerDetector")){
				this->_alternateServerDetector = (StaticContentExchange_AlternateServerDetector*)iter();
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_ClientNegotiator")){
				this->_staticContentExchange_ClientNegotiator = (StaticContentExchange_ClientNegotiator*)iter();
				break;
			}
		}
	}
}
int StaticContentExchange_ClientUnit::numInitStages() const{
	return 2;
}
void StaticContentExchange_ClientUnit::handleMessage(cMessage *msg){
	if(msg->arrivedOn("fromServicePeer")){
		this->handleFromServicePeerMessage(msg);
	}
	else if(msg->arrivedOn("fromStateTester")){
		this->handleFromStateTesterMessage(msg);
	}
	else if(msg->arrivedOn("fromAlternateServerDetector")){
		this->handleFromAlternateServerDetectorMessage(msg);
	}
	else if(msg->arrivedOn("fromNegotiator")){
		this->handleFromNegotiatorMessage(msg);
	}
	else if(msg->arrivedOn("fromServerUnit")){
		this->handleFromServerUnitMessage(msg);
	}
}
void StaticContentExchange_ClientUnit::handleFromServerUnitMessage(cMessage *msg){
	this->handleFromServicePeerMessage(msg);
}
void StaticContentExchange_ClientUnit::finish(){
}
void StaticContentExchange_ClientUnit::handleFromNegotiatorMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	decapsulateRequest_ProbagateEcho(this, &originalRequest);
}
void StaticContentExchange_ClientUnit::handleFromAlternateServerDetectorMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	if(originalRequest->getStatus() == FAILED){ //throw back to the upper level
		decapsulateRequest_ProbagateEcho(this, &originalRequest);
	}
	else if(originalRequest->getStatus() == OK){
		Request* next = originalRequest->detachNext();
		originalRequest->detachCommand(); //to avoid accidental deletion
		originalRequest->detachRequestLogEntry(); //to avoid accidental deletion
		CDN_CentralUnit_Reply* cdn_CentralUnit_Reply = (CDN_CentralUnit_Reply*)originalRequest->detachReply();//to avoid accidental deletion
		cGate* serverGate = cdn_CentralUnit_Reply->getServerGate();
		((StaticContentExchange_ServicePeerCommand*)next->getCommand())->setServerGate(serverGate);
		delete cdn_CentralUnit_Reply;
		delete originalRequest;

		encapuslateRequest_ProbagateCommand(this, next, this->gate("fromNegotiator"), this->_staticContentExchange_ClientNegotiator->gate("fromClientUnit"));
	}
}
void StaticContentExchange_ClientUnit::handleFromServicePeerMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	encapuslateRequest_ProbagateCommand(this, originalRequest, this->gate("fromStateTester"), this->_staticContentExchange_StateTester->gate("fromClientUnitOrServerUnit"));
}
void StaticContentExchange_ClientUnit::handleFromStateTesterMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	if(originalRequest->getStatus() == FAILED){ //continue
		originalRequest->setReplyGate(gate("fromAlternateServerDetector"));
		originalRequest->setStatus(UNKNOWN);
		RequestMessage* requestMessage = new RequestMessage();
		requestMessage->setRequest(originalRequest);
		sendDirect(requestMessage, 0, 0, this->_alternateServerDetector->gate("fromClientUnit"));

	}
	else if(originalRequest->getStatus() == OK){//throw back to the upper level
		decapsulateRequest_ProbagateEcho(this, &originalRequest);
	}
}
