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

#define STATICCONTENTEXCHANGE_SERVERUNIT_CC
#include "StaticContentExchange_ServerUnit.h"
#include "InterNodeRequestProtocol.h"
#include "CacheLogEntry.h"
#include "RequestLogEntry.h"
Define_Module(StaticContentExchange_ServerUnit)
;
void StaticContentExchange_ServerUnit::initialize(int stage) {
	if (stage == 1) {
		uploadedBytes = 0;
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++) {
			if (iter()->isName("staticContentExchange_StateTester")) {
				this->_staticContentExchange_StateTester
						= (StaticContentExchange_StateTester*) iter();
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++) {
			if (iter()->isName("staticContentExchange_ServerNegotiator")) {
				this->_staticContentExchange_ServerNegotiator
						= (StaticContentExchange_ServerNegotiator*) iter();
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++) {
			if (iter()->isName("staticContentExchange_ClientUnit")) {
				this->_staticContentExchange_ClientUnit
						= (StaticContentExchange_ClientUnit*) iter();
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()->getParentModule()); !iter.end(); iter++) {
			if (iter()->isName("stats")) {
				this->_stats = (Stats*) iter();
				break;
			}
		}
	}
}
int StaticContentExchange_ServerUnit::numInitStages() const {
	return 2;
}
StaticContentExchange_ServerUnit::StaticContentExchange_ServerUnit() {
	uploadedBytes = 0;
}
void StaticContentExchange_ServerUnit::handleMessage(cMessage *msg) {
	if (msg->arrivedOn("fromServicePeer")) {
		this->handleFromServicePeerMessage(msg);
	} else if (msg->arrivedOn("fromStateTester")) {
		this->handleFromStateTesterMessage(msg);
	} else if (msg->arrivedOn("fromNegotiator")) {
		this->handleFromNegotiatorMessage(msg);
	} else if (msg->arrivedOn("fromClientUnit")) {
		this->handleFromClientUnitMessage(msg);
	}
}
void StaticContentExchange_ServerUnit::handleFromClientUnitMessage(
		cMessage *msg) {
	Request* cooperationRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	delete msg;
	msg = NULL;

	Request* originalRequest = cooperationRequest->detachNext();
	for (unsigned int i = 0; i < requests.size(); i++)
				if (((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getTime()
						== ((StaticContentExchange_ServicePeerCommand*) requests.at(
								i)->getCommand())->getTime()){
					requests.erase(requests.begin()+i);
					break;
				}
	RequestStatus status = cooperationRequest->getStatus();
	if (cooperationRequest->getRequestLogEntry()->getWhy()) {
		originalRequest->getRequestLogEntry()->setWhyRaw(new std::string(
				cooperationRequest->getRequestLogEntry()->getWhy()->c_str()));
		std::ostringstream o;
		o << simTime();
		originalRequest->getRequestLogEntry()->setWhy(new std::string(
				getParentModule()->getName()),
				new std::string(o.str().c_str()),
				new std::string("FAILED PULL"));
	}
	//~ Stats start
	//no need to update cooperationRequest->getRequestLogEntry() since we delete it
	//~ Stats end
	delete cooperationRequest;
	cooperationRequest = NULL;
	if (status == FAILED) {
		originalRequest->setStatus(FAILED);
		decapsulateRequest_ProbagateEcho(this, &originalRequest);
	} else if (status == OK) {
		originalRequest->setStatus(UNKNOWN);
		originalRequest->setReplyGate(gate("fromNegotiator"));
		RequestMessage* requestMessage = new RequestMessage();
		requestMessage->setRequest(originalRequest);
		sendDirect(requestMessage, 0, 0,
				this->_staticContentExchange_ServerNegotiator->gate(
						"fromServerUnit"));
		for (unsigned int i = 0; i < requests.size(); i++)
					if (((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getObjectId()
							== ((StaticContentExchange_ServicePeerCommand*) requests.at(
									i)->getCommand())->getObjectId()){
						requests.at(i)->setStatus(UNKNOWN);
						requests.at(i)->setReplyGate(gate("fromNegotiator"));
						RequestMessage* requestMessage = new RequestMessage();
						requestMessage->setRequest(requests.at(i));
						sendDirect(requestMessage, 0, 0,
								this->_staticContentExchange_ServerNegotiator->gate(
										"fromServerUnit"));
					}
	}
}
void StaticContentExchange_ServerUnit::handleFromNegotiatorMessage(
		cMessage *msg) {
	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	delete msg;
	msg = NULL;

	decapsulateRequest_ProbagateEcho(this, &originalRequest);
}
void StaticContentExchange_ServerUnit::finish() {
}
void StaticContentExchange_ServerUnit::handleFromStateTesterMessage(
		cMessage* msg) {
	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	delete msg;
	msg = NULL;

	//~ Stats start
	//we count miss or hit only if it was a client request to a surrogate server (not cooperation)
	if (originalRequest->getRequestLogEntry()->getInitiator() == CLIENT
			&& !strcmp(getParentModule()->par("type"), "s")) {
		CacheLogEntry* cacheLogEntry = new CacheLogEntry();
		if (!strcmp(getParentModule()->par("type"), "s")) {
			cacheLogEntry->setInitiator(SURROGATE);
		}
		if (originalRequest->getStatus() == FAILED) {
			cacheLogEntry->setCacheStatus(MISS);
		}
		if (originalRequest->getStatus() == OK) {
			cacheLogEntry->setCacheStatus(HIT);
		}
		cacheLogEntry->setObjectId(
				((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getObjectId());
		cacheLogEntry->setTimeStamp(SIMTIME_DBL(simTime()));
		cacheLogEntry->setServerName(new std::string(
				getParentModule()->getName()));
		this->_stats->dumpCacheLogEntry(cacheLogEntry);
		delete cacheLogEntry;
		cacheLogEntry = NULL;
	}
	//monitor origins also, the traffic caused both by clients and surrogate servers
	if (!strcmp(getParentModule()->par("type"), "o")) {
		CacheLogEntry* cacheLogEntry = new CacheLogEntry();
		if (!strcmp(getParentModule()->par("type"), "o")) {
			cacheLogEntry->setInitiator(ORIGIN);
		}
		if (originalRequest->getStatus() == FAILED) {
			cacheLogEntry->setCacheStatus(MISS);
		}
		if (originalRequest->getStatus() == OK) {
			cacheLogEntry->setCacheStatus(HIT);
		}
		cacheLogEntry->setObjectId(
				((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getObjectId());
		cacheLogEntry->setTimeStamp(SIMTIME_DBL(simTime()));
		cacheLogEntry->setServerName(new std::string(
				getParentModule()->getName()));
		this->_stats->dumpCacheLogEntry(cacheLogEntry);
		delete cacheLogEntry;
		cacheLogEntry = NULL;
	}
	//~ Stats end
	if (originalRequest->getStatus() == FAILED) { //continue
		//try to get from other server
		bool alreadyReq = false;
		for (unsigned int i = 0; i < requests.size(); i++)
			if (((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getObjectId()
					== ((StaticContentExchange_ServicePeerCommand*) requests.at(
							i)->getCommand())->getObjectId()){
				alreadyReq = true;
				break;
			}
		vector<Request*>::iterator it;
		it = requests.begin();
		requests.insert(it, originalRequest);
		if(alreadyReq == false){
			//Issue a new command!
			StaticContentExchange_ServicePeerCommand* cooperativeCommand =
					new StaticContentExchange_ServicePeerCommand();
			cooperativeCommand->setTime(SIMTIME_DBL(simTime()));
			cooperativeCommand->setObjectId(
					((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getObjectId());

			Request* cooperationRequest = new Request();
			cooperationRequest->setCommand(cooperativeCommand);
			cooperationRequest->setNext(originalRequest);
			cooperationRequest->setReplyGate(gate("fromClientUnit"));
			cooperationRequest->setTransportType(originalRequest->getTransportType());
			//~ Stats start
			RequestLogEntry* requestLogEntry = new RequestLogEntry();

			requestLogEntry->setRequestStartTime(SIMTIME_DBL(simTime()));
			requestLogEntry->setRequesterName(new std::string(
					getParentModule()->getName()));
			if (!strcmp(getParentModule()->par("type"), "s")) {
				requestLogEntry->setInitiator(SURROGATE);
			}
			if (!strcmp(getParentModule()->par("type"), "c")) {
				throw cRuntimeError("Client makes request (line: %d, file: %s)",
						__LINE__, __FILE__);
			}

			if (!strcmp(getParentModule()->par("type"), "o")) {
				throw cRuntimeError(
						"Origin makes cooperation request (line: %d, file: %s)",
						__LINE__, __FILE__);
			}
			requestLogEntry->setObjectId(cooperativeCommand->getObjectId());

			cooperationRequest->setRequestLogEntry(requestLogEntry);
			//~ Stats end
			RequestMessage* requestMessage = new RequestMessage();
			requestMessage->setRequest(cooperationRequest);
			sendDirect(requestMessage, 0, 0, this->_staticContentExchange_ClientUnit->gate("fromServerUnit"));
		}
	} else if(originalRequest->getStatus() == OK) {
		originalRequest->setStatus(UNKNOWN);
		originalRequest->setReplyGate(gate("fromNegotiator"));
		RequestMessage* requestMessage = new RequestMessage();
		requestMessage->setRequest(originalRequest);
		sendDirect(requestMessage, 0, 0, this->_staticContentExchange_ServerNegotiator->gate("fromServerUnit"));
	}
}
void StaticContentExchange_ServerUnit::handleFromServicePeerMessage(
		cMessage *msg) {
	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	delete msg;
	msg = NULL;

	encapuslateRequest_ProbagateCommand(this, originalRequest, this->gate(
			"fromStateTester"), this->_staticContentExchange_StateTester->gate(
			"fromClientUnitOrServerUnit"));
}
