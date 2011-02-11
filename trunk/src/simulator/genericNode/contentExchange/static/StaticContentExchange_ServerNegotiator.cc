#define STATICCONTENTEXCHANGE_SERVERNEGOTIATOR_CC
#include "StaticContentExchange_ServerNegotiator.h"
#include "InterNodeRequestProtocol.h"
#include "StaticContentExchange_ServicePeer.h"
#include "Exceptions.h"
Define_Module(StaticContentExchange_ServerNegotiator)
;
void StaticContentExchange_ServerNegotiator::initialize(int stage) {
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
int StaticContentExchange_ServerNegotiator::numInitStages() const {
	return 3;
}
void StaticContentExchange_ServerNegotiator::handleMessage(cMessage *msg) {
	if (msg->arrivedOn("fromServerUnit")) {
		this->handleFromServerUnitMessage(msg);
	} else if (msg->arrivedOn("fromServerHandler")) {
		this->handleFromServerHandlerMessage(msg);
	}
}
void StaticContentExchange_ServerNegotiator::finish() {
}
void StaticContentExchange_ServerNegotiator::handleFromServerUnitMessage(
		cMessage *msg) {
	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	delete msg;
	msg = NULL;
	Handler* serverHandler = NULL;
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
		if (!strcmp(getParentModule()->par("type"), "o")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Origin: No available ephemeral port"));
		}

		decapsulateRequest_ProbagateEcho(this, &originalRequest);
		return;
	}
	try {
		serverHandler
				= this->_staticContentExchange_State->getAvailableServerHandler(originalRequest->getTransportType());
		try {
			serverHandler->lock();
		} catch (cRuntimeError* e) {
			opp_error("TRYING TO LOCK AN ALREADY LOCKED SERVER HANDLER");
		}
		encapuslateRequest_ProbagateCommand(this, originalRequest, this->gate(
				"fromServerHandler"), serverHandler->gate(
				"fromServerNegotiator"));
	} catch (cRuntimeError* e) {
		//cout << getParentModule()->getName() << " " << e->message() <<endl;
		delete e;
		e = NULL;
		originalRequest->setStatus(FAILED);
		if (!strcmp(getParentModule()->par("type"), "s")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Surrogate: No available server handler"));
		}
		if (!strcmp(getParentModule()->par("type"), "o")) {
			std::ostringstream o;
			o << simTime();
			originalRequest->getRequestLogEntry()->setWhy(new std::string(
					getParentModule()->getName()), new std::string(
					o.str().c_str()), new std::string(
					"Origin: No available server handler"));
		}

		decapsulateRequest_ProbagateEcho(this, &originalRequest);
		return;
	}
}
void StaticContentExchange_ServerNegotiator::handleFromServerHandlerMessage(
		cMessage *msg) {
	((Handler*) msg->getSenderModule())->unlock();
	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	delete msg;
	msg = NULL;

	decapsulateRequest_ProbagateEcho(this, &originalRequest);
}
