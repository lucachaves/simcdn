#define STATICCONTENTEXCHANGE_CLIENTNEGOTIATOR_CC
#include "StaticContentExchange_ClientNegotiator.h"
#include "Request.h"
#include "RequestMessage.h"
#include "InterNodeRequestProtocol.h"
#include "StaticContentExchange_ServicePeerCommand.h"
#include "StaticContentExchange_ServicePeer.h"
#include "Handler.h"
#include "Exceptions.h"
#include <IPAddressResolver.h>
#include <string>

Define_Module(StaticContentExchange_ClientNegotiator);
void StaticContentExchange_ClientNegotiator::initialize(int stage) {
	if (stage == 2) {
		StaticContentExchange_ServicePeer* staticContentExchange_ServicePeer =
				NULL;
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++) {
			if (iter()->isName("staticContentExchange_ServicePeer")) {
				staticContentExchange_ServicePeer
						= (StaticContentExchange_ServicePeer*) iter();
				break;
			}
		}
		this->_staticContentExchange_State
				= staticContentExchange_ServicePeer->getState();
	}
}
int StaticContentExchange_ClientNegotiator::numInitStages() const {
	return 3;
}
void StaticContentExchange_ClientNegotiator::handleMessage(cMessage *msg) {
	if (msg->arrivedOn("fromClientUnit")) {
		this->handleFromClientUnitMessage(msg);
	} else if (msg->arrivedOn("fromRequestsReceiverAssigner")) {
		this->handleFromRequestsReceiverAssignerMessage(msg);
	} else if(msg->arrivedOn("fromUDPClient")){
		this->handleFromUDPClient(msg);
	}
}
void StaticContentExchange_ClientNegotiator::finish() {
}
void StaticContentExchange_ClientNegotiator::handleFromClientUnitMessage(
		cMessage *msg) {
	if (!strcmp(getParentModule()->par("type"), "o")) {
		throw cRuntimeError("Origin is asking for object (line: %d, file: %s)",
				__LINE__, __FILE__);
	}

	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	delete msg;
	msg = NULL;
	Handler* clientHandler = NULL;
	if (!_staticContentExchange_State->hasAvailableEphemeralPorts(originalRequest->getTransportType())) {
		originalRequest->setStatus(FAILED);
		if (!strcmp(getParentModule()->par("type"), "s")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Surrogate: No available ephemeral port"));
		}
		if (!strcmp(getParentModule()->par("type"), "c")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Client: No available ephemeral port"));
		}
		decapsulateRequest_ProbagateEcho(this, &originalRequest);
		return;

	}
	try {
		clientHandler
				= this->_staticContentExchange_State->getAvailableClientHandler(originalRequest->getTransportType());
	} catch (cRuntimeError* e) {
		ev << e->what() << endl;
		delete e;
		e = NULL;
		originalRequest->setStatus(FAILED);
		if (!strcmp(getParentModule()->par("type"), "s")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Surrogate: No available client handler"));
		}
		if (!strcmp(getParentModule()->par("type"), "c")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Client: No available client handler"));
		}
		decapsulateRequest_ProbagateEcho(this, &originalRequest);
		return;
	}
	try {
		this->_staticContentExchange_State->reserveDownloader();
		((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->setServePort(
				clientHandler->par("port"));
		((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->setServeAddress(
				IPAddressResolver().addressOf(getParentModule()));
		encapuslateRequest_ProbagateCommand(
				this,
				originalRequest,
				this->gate("fromRequestsReceiverAssigner"),
				((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getServerGate());
	} catch (cRuntimeError* e) {
		ev << e->what() << endl;
		delete e;
		e = NULL;
		originalRequest->setStatus(FAILED);
		if (!strcmp(getParentModule()->par("type"), "s")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Surrogate: No available downloader"));
		}
		if (!strcmp(getParentModule()->par("type"), "c")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Client: No available downloader"));
		}
		decapsulateRequest_ProbagateEcho(this, &originalRequest);
		return;
	}

}
void StaticContentExchange_ClientNegotiator::handleFromRequestsReceiverAssignerMessage(
		cMessage *msg) {
	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	this->_originalRequest.push_back(originalRequest);
	delete msg;
	msg = NULL;
	if(originalRequest->getTransportType() == TCP_P){
		this->_staticContentExchange_State->freeDownloader();
		this->_originalRequest.pop_back();
		decapsulateRequest_ProbagateEcho(this, &originalRequest);
	}


}

void StaticContentExchange_ClientNegotiator::handleFromUDPClient(cMessage *msg){
	delete msg;
	msg = NULL;
	this->_staticContentExchange_State->freeDownloader();
	Request* originalRequest = this->_originalRequest.back();
	this->_originalRequest.pop_back();
	decapsulateRequest_ProbagateEcho(this, &originalRequest);
}

