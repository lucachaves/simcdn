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

#define CDN_REQUESTSASSIGNERRECEIVER_CC
#include "CDN_RequestsAssignerReceiver.h"
#include "Request.h"
#include "RequestMessage.h"
#include "Exceptions.h"
#include "CDN_CentralUnit.h"
#include "InterNodeRequestProtocol.h"
#include <assert.h>
Define_Module(CDN_RequestsAssignerReceiver);

#define RAND_UNIFORME (double)random()/(double)RAND_MAX

double random_exp(double mean)
{
	double landa = 1.0 / (double)mean;
	return (-log(1.0-RAND_UNIFORME)/(double)landa);
};

void CDN_RequestsAssignerReceiver::initialize(int stage){
	if(stage == 0){
		this->commandsScriptFilename = par("commandsScript");
		_commands->loadScript(this->commandsScriptFilename, getParentModule()->par("type"));
		this->nRetries = par("nRetries");
		this->mean = par("mean");
	}
	if(stage == 1){
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_ServicePeer")){
				this->_staticContentExchange_ServicePeer = (StaticContentExchange_ServicePeer*)iter();
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()->getParentModule()); !iter.end(); iter++){
			if (iter()->isName("cdn_CentralUnit")){
				if(!strcmp(getParentModule()->par("type"), "o")){
					((CDN_CentralUnit*)iter())->registerOriginServer(this);
				}
				if(!strcmp(getParentModule()->par("type"), "s")){
					((CDN_CentralUnit*)iter())->registerSurrogateServer(this);
				}
				if(!strcmp(getParentModule()->par("type"), "c")){
					((CDN_CentralUnit*)iter())->registerClient(this);
				}
				break;
			}
		}
		for (cModule::SubmoduleIterator iter(getParentModule()->getParentModule()); !iter.end(); iter++){
			if (iter()->isName("stats")){
				this->_stats = (Stats*)iter();
				//~ Stats start
				this->_stats->addTotalRequests(_commands->getNumberOfCommands());
				//~ Stats end
				break;
			}
		}
	}
	if(stage == 2){//used to trigger the first command (if any)
		this->scheduleNextCommand();
	}
}
int CDN_RequestsAssignerReceiver::numInitStages() const{
	return 3;
}
void CDN_RequestsAssignerReceiver::handleMessage(cMessage *msg){
	if(msg->isSelfMessage() ){
		this->handleSelfMessage(msg);
	}
	else if(msg->arrivedOn("fromNegotiator")){
		this->handleFromNegotiatorMessage(msg);
	}
	else if(msg->arrivedOn("fromServicePeer")){
		this->handleFromServicePeerMessage(msg);
	}
	else if(msg->arrivedOn("fromCentralUnit")){
		this->handleFromCentralUnitMessage(msg);
	}
	else if(msg->arrivedOn("retry")){
		this->handleFromRetry(msg);
	}
}
void CDN_RequestsAssignerReceiver::finish(){
}
void CDN_RequestsAssignerReceiver::handleSelfMessage(cMessage *msg){
	delete msg; msg = NULL;
	StaticContentExchange_ServicePeerCommand* command = this->_commands->detachNextCommand();

	Request* request = new Request();
	request->setCommand( command );
	request->setTransportType(command->getTransportType());
	request->setReplyGate(this->gate("fromServicePeer"));


	//~ Stats start
	RequestLogEntry* requestLogEntry = new RequestLogEntry();

	requestLogEntry->setRequestStartTime(SIMTIME_DBL(simTime()));
	requestLogEntry->setRequesterName(new std::string(getParentModule()->getName()));
	if(!strcmp(getParentModule()->par("type"), "s")){
		//TODO throw cRuntimeError("surrogate makes request (line: %d, file: %s)", __LINE__, __FILE__);
		requestLogEntry->setInitiator(SURROGATE);
	}
	if(!strcmp(getParentModule()->par("type"), "c")){
		requestLogEntry->setInitiator(CLIENT);
	}

	if(!strcmp(getParentModule()->par("type"), "o")){
		throw cRuntimeError("Origin makes request (line: %d, file: %s)", __LINE__, __FILE__);
	}
	requestLogEntry->setObjectId(command->getObjectId());

	request->setRequestLogEntry(requestLogEntry);
	//~ Stats end



	//Pack it inside a message
	RequestMessage* requestMessage = new RequestMessage();
	requestMessage->setRequest(request);

	//send it
	this->sendDirect(requestMessage, 0, 0, this->_staticContentExchange_ServicePeer->gate("fromCDN_RequestsAssignerReceiverToClientUnit"));
	//~ Stats start
	this->_stats->incGeneratedRequests();
	////~ Stats end
	this->scheduleNextCommand();
}
void CDN_RequestsAssignerReceiver::handleFromCentralUnitMessage(cMessage *msg){
	Request* request = ((RequestMessage*)msg)->detachRequest(); //detach the echo-request
	delete msg; msg = NULL;
	StaticContentExchange_ServicePeerCommand* staticContentExchange_ServicePeerCommand = (StaticContentExchange_ServicePeerCommand*)request->getCommand();
	this->_commands->insertCommandByTime(staticContentExchange_ServicePeerCommand);
	if(staticContentExchange_ServicePeerCommand->getFlag())
		scheduleAt(staticContentExchange_ServicePeerCommand->getTime(), new cMessage());
}
void CDN_RequestsAssignerReceiver::handleFromNegotiatorMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	encapuslateRequest_ProbagateCommand(this, originalRequest, this->gate("fromServicePeer"), this->_staticContentExchange_ServicePeer->gate("fromCDN_RequestsAssignerReceiverToServerUnit"));
}
void CDN_RequestsAssignerReceiver::handleFromServicePeerMessage(cMessage *msg){
	Request* echoRequest = ((RequestMessage*)msg)->detachRequest(); //detach the echo-request
	delete msg; msg = NULL; //now we can discard the incoming message

	//~ Stats start
	if(!echoRequest->getNext()){
		echoRequest->getRequestLogEntry()->setRequestEndTime(SIMTIME_DBL(simTime()));

		if(echoRequest->getStatus() == FAILED){
			echoRequest->getRequestLogEntry()->setStatus(ABORTED);
		}
		else{
			if(echoRequest->getStatus() == OK){
				echoRequest->getRequestLogEntry()->setStatus(COMPLETED);
				//~ Stats start
				this->_stats->incCompletedRequests();
				////~ Stats end
			}
			else{
				throw cRuntimeError("Unknown request status (line: %d, file: %s)", __LINE__, __FILE__);
			}
		}
		if( (echoRequest->getRequestLogEntry()->getRetries() < nRetries) && (echoRequest->getRequestLogEntry()->getStatus() == ABORTED)){
			//prepare a retry
			RequestMessage* requestMessage = new RequestMessage();
			requestMessage->setRequest(echoRequest);
			this->sendDirect(requestMessage, random_exp(this->mean), 0, this->gate("retry"));
			return;
		}
		else{
			this->_stats->dumpRequestLogEntry(echoRequest->getRequestLogEntry());
			if(echoRequest->getRequestLogEntry()->getStatus() == ABORTED){
			  //~ Stats start
				this->_stats->incFailedRequests();
				////~ Stats end
			}

		}
	}
	//~Stats end

	decapsulateRequest_ProbagateEcho(this, &echoRequest);
}
CDN_RequestsAssignerReceiver::CDN_RequestsAssignerReceiver(){
	this->nRetries = 0;
	this->mean = 0;
	this->_commands = new CDN_Commands();
	this->commandsScriptFilename = NULL;
	this->_staticContentExchange_ServicePeer = NULL;
	this->_marchEvent = new cMessage();
}
CDN_RequestsAssignerReceiver::~CDN_RequestsAssignerReceiver(){
	delete _commands;
	cancelAndDelete(this->_marchEvent);
}
void CDN_RequestsAssignerReceiver::scheduleNextCommand(){
	try{
		if(simTime() > this->_commands->getGetNextCommandTime()){
			throw new PastException();
		}
	}
	catch (NoCommandsException* e){
		delete e;
		return;
	}

	//TODO
//	if(this->_marchEvent->isScheduled()){
//		throw new AlreadyScheduledException();
//	}
//	scheduleAt(this->_commands->getGetNextCommandTime(), this->_marchEvent);
	scheduleAt(this->_commands->getGetNextCommandTime(), new cMessage());
}
StaticContentExchange_State* CDN_RequestsAssignerReceiver::getStaticContentExchangeState(){
	return this->_staticContentExchange_ServicePeer->getState();
}
void CDN_RequestsAssignerReceiver::handleFromRetry(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	originalRequest->setStatus(UNKNOWN);
	originalRequest->getRequestLogEntry()->incRetries();

	//Pack it inside a message
	RequestMessage* requestMessage = new RequestMessage();
	requestMessage->setRequest(originalRequest);

	//perfrom a retry
	this->sendDirect(requestMessage, 0, 0, this->_staticContentExchange_ServicePeer->gate("fromCDN_RequestsAssignerReceiverToClientUnit"));
	//~ Stats start
	this->_stats->incGeneratedRetries();
	////~ Stats end
}
