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

#define STATICCONTENTEXCHANGE_UDPCLIENTHANDLER_CC
#include "StaticContentExchange_UDPClientHandler.h"
#include "StaticContentExchange_ServicePeer.h"
#include "StaticObjectMessage.h"
#include "UDPSocket.h"
#include "UDPControlInfo_m.h"
#include "Exceptions.h"
#include "RequestMessage.h"
#include "Request.h"
#include "InterNodeRequestProtocol.h"
#include <assert.h>

Define_Module(StaticContentExchange_UDPClientHandler);
void StaticContentExchange_UDPClientHandler::bindToPort(int port)
{
    EV << "Binding to UDP port " << port << endl;

    // TODO UDPAppBase should be ported to use UDPSocket sometime, but for now
    // we just manage the UDP socket by hand...
    cMessage *msg = new cMessage("UDP_C_BIND", UDP_C_BIND);
    UDPControlInfo *ctrl = new UDPControlInfo();
    ctrl->setSrcPort(port);
    ctrl->setSockId(UDPSocket::generateSocketId());
    msg->setControlInfo(ctrl);
    send(msg, "udpOut");
}

void StaticContentExchange_UDPClientHandler::sendToUDP(cPacket *msg, int srcPort, const IPvXAddress& destAddr, int destPort)
{
    // send message to UDP, with the appropriate control info attached
    msg->setKind(UDP_C_DATA);

    UDPControlInfo *ctrl = new UDPControlInfo();
    ctrl->setSrcPort(srcPort);
    ctrl->setDestAddr(destAddr);
    ctrl->setDestPort(destPort);
    msg->setControlInfo(ctrl);

    EV << "Sending packet: ";
    printPacket(msg);

    send(msg, "udpOut");
}

void StaticContentExchange_UDPClientHandler::printPacket(cPacket *msg)
{
    UDPControlInfo *ctrl = check_and_cast<UDPControlInfo *>(msg->getControlInfo());

    IPvXAddress srcAddr = ctrl->getSrcAddr();
    IPvXAddress destAddr = ctrl->getDestAddr();
    int srcPort = ctrl->getSrcPort();
    int destPort = ctrl->getDestPort();

    ev  << msg << "  (" << msg->getByteLength() << " bytes)" << endl;
    ev  << srcAddr << " :" << srcPort << " --> " << destAddr << ":" << destPort << endl;
}
void StaticContentExchange_UDPClientHandler::initialize(int stage) {
	if (stage == 2) {
		downloadedBytes = 0;
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
		this->_staticContentExchange_State->registerClientHandler(this);
		bindToPort( par("port"));
	}
}
int StaticContentExchange_UDPClientHandler::numInitStages() const {
	return 3;
}

void StaticContentExchange_UDPClientHandler::handleMessage(cMessage *msg) {
	if (msg->isSelfMessage()) {
		delete msg;
	} else {
		receiveStream(PK(msg));
	}
}
TranspotType StaticContentExchange_UDPClientHandler::getTransportType(){
	return this->transportType;
}

void StaticContentExchange_UDPClientHandler::receiveStream(cPacket *msg) {
	EV<< "Video stream packet:\n";
	printPacket(msg);
	this->downloadedBytes += msg->getByteLength();
	cout << "UTIL_DOWN "<< cSimulation::getActiveSimulation()->getSimTime() << " "<< this->getParentModule()->getName() <<" " << this->downloadedBytes << endl;
	StaticObject* object = ((StaticObjectMessage*)msg)->detachObject();
	assert(object);
	//store in cache
	try{
		this->_staticContentExchange_State->getCache()->getNonExistingObject(object);
	}
	catch(ObjectAlreadyExistsException* e){
		delete e; e=NULL;
		//FIXME object already exists do something?
		//in the case of a surrogate we can use later the getObjectForced()
	}
	catch(ObjectTooBigException* e){
		delete e; e=NULL;
		//FIXME object too big do something?
		//in the case of a surrogate we can use later the getObjectForced()
	}
	StaticContentExchange_ClientNegotiator* staticContentExchange_ClientNegotiator = NULL;
	for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++) {
		if (iter()->isName("staticContentExchange_ClientNegotiator")) {
			staticContentExchange_ClientNegotiator = (StaticContentExchange_ClientNegotiator*)iter();
			break;
		}
	}
	RequestMessage* requestMessage = new RequestMessage();
	sendDirect(requestMessage, staticContentExchange_ClientNegotiator->gate("fromUDPClient"));
	delete msg; msg = NULL;
}

void StaticContentExchange_UDPClientHandler::finish() {
}

bool StaticContentExchange_UDPClientHandler::isLocked() {
	return this->locked;
}
void StaticContentExchange_UDPClientHandler::lock() {
	if (this->locked) {
		throw cRuntimeError(
				"Trying to lock an already locked client handler (line: %d, file: %s)",
				__LINE__, __FILE__);
			}
			this->locked = true;
		}
void StaticContentExchange_UDPClientHandler::unlock() {
	if (!this->locked) {
		throw cRuntimeError(
				"Trying to unlock an already unlocked client handler (line: %d, file: %s)",
				__LINE__, __FILE__);
			}
			this->locked = false;
		}
StaticContentExchange_UDPClientHandler::StaticContentExchange_UDPClientHandler() {
	this->transportType = UDP_P;
	this->downloadedBytes = 0;
	this->locked = false;
}
