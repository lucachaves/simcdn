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
#define STATICCONTENTEXCHANGE_TCPSERVERHANDLER_CC
#include "StaticContentExchange_TCPServerHandler.h"
#include "StaticContentExchange_ServicePeer.h"
#include "Request.h"
#include "RequestMessage.h"
#include "Exceptions.h"
#include "LruCache.h"
#include "StaticObject.h"
#include "InterNodeRequestProtocol.h"
#include "StaticContentExchange_ServicePeerCommand.h"
#include "StaticObjectMessage.h"
#include <assert.h>
Define_Module(StaticContentExchange_TCPServerHandler);
#define TIMEOUT 0
void StaticContentExchange_TCPServerHandler::initialize(int stage){
	if(stage == 2){
		StaticContentExchange_ServicePeer* staticContentExchange_ServicePeer = NULL;
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_ServicePeer")){
				staticContentExchange_ServicePeer = (StaticContentExchange_ServicePeer*)iter();
				break;
			}
		}
		this->_staticContentExchange_State = staticContentExchange_ServicePeer->getState();
		_staticContentExchange_State->registerServerHandler(this);

          _staticContentExchange_ServerUnit = 0;
          for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
               if (iter()->isName("staticContentExchange_ServerUnit")){
                    this->_staticContentExchange_ServerUnit = (StaticContentExchange_ServerUnit*)iter();
                    break;
                    cout << "BIATCH";
               }
          }
          assert(_staticContentExchange_ServerUnit);

		socket.setOutputGate(gate("tcpOut"));
		socket.bind(IPAddressResolver().addressOf(getParentModule()), par("port"));
		socket.setCallbackObject(this);
	}
}

void StaticContentExchange_TCPServerHandler::handleMessage(cMessage *msg){
	if (msg->isSelfMessage())
	{
		delete msg; msg = NULL;
		return;
	}else{
		if(msg->arrivedOn("fromServerNegotiator")){
			//get a new request from
			this->currentRequest = ((RequestMessage*)msg)->detachRequest(); //recieve the request
			delete msg; msg = NULL;

			//get cache
			Cache* cache = (Cache*)this->_staticContentExchange_State->getInformationSet();
			try{
				//get object from cache
				this->currentObject =  cache->getExistingObject(((StaticContentExchange_ServicePeerCommand*)this->currentRequest->getCommand())->getObjectId())->clone();
			}
			catch(ObjectDoesNotExistException* e){
				//quick and dirty. If a surrogate is assigned to serve an object, this objects must be in cache.
				this->currentObject =  cache->getObjectForced(((StaticContentExchange_ServicePeerCommand*)this->currentRequest->getCommand())->getObjectId())->clone();
// 				delete e; e = NULL;
// 				this->currentRequest->setStatus(FAILED);
// 				this->currentRequest->getRequestLogEntry()->setWhy(new std::string("Surrogate: Unexpected cache miss"));
// 				RequestMessage* requestMessage = new RequestMessage();
// 				requestMessage->setRequest(this->currentRequest);
// 				sendDirect(requestMessage, 0, this->currentRequest->getReplyGate());
// 				this->currentRequest = NULL;
// 				this->currentObject = NULL;
			}

			//connect
			//cout << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": New Connection, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
			socket.renewSocket();
			//cout << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": Connecting, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
			socket.connect(((StaticContentExchange_ServicePeerCommand*)this->currentRequest->getCommand())->getServeAddress(), ((StaticContentExchange_ServicePeerCommand*)this->currentRequest->getCommand())->getServePort());
			return;
		}
		else{
			if(socket.belongsToSocket(msg)){
				socket.processMessage(msg);
				return;
			}
			else{
				cerr << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": Old Connection's packet recieved, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
				delete msg; msg = NULL;
				return;
			}
		}
	}
}
void StaticContentExchange_TCPServerHandler::finish(){
}
int StaticContentExchange_TCPServerHandler::numInitStages() const{
	return 3;
}

void StaticContentExchange_TCPServerHandler::socketDataArrived(int, void *, cPacket *msg, bool urgent){
	throw cRuntimeError("Server Handler recieved data (line: %d, file: %s)", __LINE__, __FILE__);
}
void StaticContentExchange_TCPServerHandler::socketEstablished(int, void *){
	//cout << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": Connection Established, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
	transmitObject();
	return;
}
void StaticContentExchange_TCPServerHandler::transmitObject(){
	StaticObjectMessage *newMsg = NULL;
	newMsg = new StaticObjectMessage("data");
	newMsg->setByteLength((int)this->currentObject->getSize()); //FIXME conversion from double to int
	newMsg->setObject(this->currentObject);
	//send message
	_staticContentExchange_ServerUnit->uploadedBytes += newMsg->getByteLength();//LUIZ this->currentObject->getSize();
	cout << "UTIL_UP "<< simTime() << " "<< getParentModule()->getName() << " " << _staticContentExchange_ServerUnit->uploadedBytes << endl;
	//cout << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": Sending, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
	socket.send(newMsg);
	socket.close();
}
void StaticContentExchange_TCPServerHandler::socketPeerClosed(int, void *){
	//close
	//cout << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": Peer Closed, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;

}
void StaticContentExchange_TCPServerHandler::socketClosed(int, void *){
	//cout << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": Socket Closed, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
	if( !(this->currentRequest->getStatus()==FAILED) ){//check if aborted
		this->currentRequest->setStatus(OK);
	}
	RequestMessage* requestMessage = new RequestMessage();
	requestMessage->setRequest(this->currentRequest);
	sendDirect(requestMessage, 0, 0, this->currentRequest->getReplyGate());
	this->currentRequest = NULL;
	this->currentObject = NULL;
	return;
}
void StaticContentExchange_TCPServerHandler::socketFailure(int, void *, int code){
	cerr << "INFO ("<< simTime() << "): "<< getParentModule()->getName() << ":" << getName() << ": SOCKERROR, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
	this->currentRequest->setStatus(FAILED); //indication that it is aborted
	std::ostringstream o;
	o << simTime();
	this->currentRequest->getRequestLogEntry()->setWhy(new std::string(getParentModule()->getName()), new std::string(o.str().c_str()), new std::string("SOCKERROR"));
	socket.abort();

	RequestMessage* requestMessage = new RequestMessage();
	requestMessage->setRequest(this->currentRequest);
	sendDirect(requestMessage, 0, 0, this->currentRequest->getReplyGate());
	this->currentRequest = NULL;
	this->currentObject = NULL;

	return;
}
void StaticContentExchange_TCPServerHandler::socketStatusArrived(int, void *, TCPStatusInfo *status){
	delete status; status = NULL;
}

bool StaticContentExchange_TCPServerHandler::isLocked(){
	return this->locked;
}
void StaticContentExchange_TCPServerHandler::lock(){
	if(this->locked){
		throw cRuntimeError("Trying to lock an already locked server handler (line: %d, file: %s)", __LINE__, __FILE__);
	}
	this->locked = true;
}
void StaticContentExchange_TCPServerHandler::unlock(){
	if(! (this->locked) ){
		throw cRuntimeError("Trying to unlock an already unlocked server handler (line: %d, file: %s)", __LINE__, __FILE__);
	}
	this->locked = false;
}
StaticContentExchange_TCPServerHandler::StaticContentExchange_TCPServerHandler(){
	this->transportType = TCP_P;
	this->locked = false;
	this->currentRequest = NULL;
	this->currentObject = NULL;
}
TranspotType StaticContentExchange_TCPServerHandler::getTransportType(){
	return this->transportType;
}
