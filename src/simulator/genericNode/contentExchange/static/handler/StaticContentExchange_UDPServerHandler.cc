#define STATICCONTENTEXCHANGE_UDPSERVERHANDLER_CC
#include "StaticContentExchange_UDPServerHandler.h"
#include "StaticContentExchange_ServicePeer.h"
#include "Request.h"
#include "RequestMessage.h"
#include "Exceptions.h"
#include "LruCache.h"
#include "StaticObject.h"
#include "InterNodeRequestProtocol.h"
#include "StaticContentExchange_ServicePeerCommand.h"
#include "StaticObjectMessage.h"
#include "UDPSocket.h"
#include "UDPControlInfo_m.h"
#include <assert.h>
Define_Module( StaticContentExchange_UDPServerHandler);
#define TIMEOUT 0
void StaticContentExchange_UDPServerHandler::bindToPort(int port) {
	EV<< "Binding to UDP port " << port << endl;

	// TODO UDPAppBase should be ported to use UDPSocket sometime, but for now
	// we just manage the UDP socket by hand...
	cMessage *msg = new cMessage("UDP_C_BIND", UDP_C_BIND);
	UDPControlInfo *ctrl = new UDPControlInfo();
	ctrl->setSrcPort(port);
	ctrl->setSockId(UDPSocket::generateSocketId());
	msg->setControlInfo(ctrl);
	send(msg, "udpOut");
}

void StaticContentExchange_UDPServerHandler::sendToUDP(cPacket *msg,
		int srcPort, const IPvXAddress& destAddr, int destPort) {
	// send message to UDP, with the appropriate control info attached
	msg->setKind(UDP_C_DATA);

	UDPControlInfo *ctrl = new UDPControlInfo();
	ctrl->setSrcPort(srcPort);
	ctrl->setDestAddr(destAddr);
	ctrl->setDestPort(destPort);
	msg->setControlInfo(ctrl);

	EV<< "Sending packet: ";
	printPacket(msg);

	send(msg, "udpOut");
}

void StaticContentExchange_UDPServerHandler::printPacket(cPacket *msg) {
	UDPControlInfo *ctrl = check_and_cast<UDPControlInfo *> (
			msg->getControlInfo());

	IPvXAddress srcAddr = ctrl->getSrcAddr();
	IPvXAddress destAddr = ctrl->getDestAddr();
	int srcPort = ctrl->getSrcPort();
	int destPort = ctrl->getDestPort();

	ev << msg << "  (" << msg->getByteLength() << " bytes)" << endl;
	ev << srcAddr << " :" << srcPort << " --> " << destAddr << ":" << destPort
			<< endl;
}


void StaticContentExchange_UDPServerHandler::sendStreamData(cMessage *timer) {


//	// generate and send a packet
//	cPacket *pkt = new cPacket("VideoStrmPk");
//	//long pktLen = packetLen->longValue();
//	if (pktLen > d->bytesLeft)
//		pktLen = d->bytesLeft;
//	pkt->setByteLength(pktLen);
//	sendToUDP(pkt, serverPort, d->clientAddr, d->clientPort);
//
//	d->bytesLeft -= pktLen;
//	d->numPkSent++;
//	numPkSent++;
//
//	// reschedule timer if there's bytes left to send
//	if (d->bytesLeft != 0) {
//		//simtime_t interval = (*waitInterval);
//		scheduleAt(simTime() + interval, timer);
//	} else {
//		delete timer;
//		// TBD find StreamData in streamVector and delete it
//	}
}

void StaticContentExchange_UDPServerHandler::processStreamRequest(cMessage *msg) {
//	// register video stream...
//	UDPControlInfo *ctrl = check_and_cast<UDPControlInfo *> (
//			msg->getControlInfo());
//
//
//	cMessage *timer = new cMessage("VideoStreamTmr");
//
//	// ... then transmit first packet right away
//	sendStreamData(timer);
//
//	numStreams++;
}

void StaticContentExchange_UDPServerHandler::initialize(int stage) {
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
		_staticContentExchange_State->registerServerHandler(this);

		_staticContentExchange_ServerUnit = 0;
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++) {
			if (iter()->isName("staticContentExchange_ServerUnit")) {
				this->_staticContentExchange_ServerUnit
						= (StaticContentExchange_ServerUnit*) iter();
				break;
				cout << "BIATCH";
			}
		}
		assert(_staticContentExchange_ServerUnit);

		numStreams = 0;
	}
}

void StaticContentExchange_UDPServerHandler::handleMessage(cMessage *msg) {
	if (msg->isSelfMessage()) {
		delete msg; msg = NULL;
		return;
		//sendStreamData(msg);
	} else {
		if (msg->arrivedOn("fromServerNegotiator")) {
			//get a new request from
			this->currentRequest = ((RequestMessage*) msg)->detachRequest(); //recieve the request
			delete msg;
			msg = NULL;

			//get cache
			Cache* cache = (Cache*) this->_staticContentExchange_State->getInformationSet();
			try {
				//get object from cache
				this->currentObject
						= cache->getExistingObject(
								((StaticContentExchange_ServicePeerCommand*) this->currentRequest->getCommand())->getObjectId())->clone();
			} catch (ObjectDoesNotExistException* e) {
				//quick and dirty. If a surrogate is assigned to serve an object, this objects must be in cache.
				this->currentObject
						= cache->getObjectForced(
								((StaticContentExchange_ServicePeerCommand*) this->currentRequest->getCommand())->getObjectId())->clone();
			}
			//Make Packet
			StaticObjectMessage *newMsg = NULL;
			newMsg = new StaticObjectMessage("data");
			newMsg->setByteLength((int) this->currentObject->getSize()); //FIXME conversion from double to int
			newMsg->setObject(this->currentObject);
			//send message
			_staticContentExchange_ServerUnit->uploadedBytes += newMsg->getByteLength();
			cout << "UTIL_UP " << simTime() << " " << getParentModule()->getName()
					<< " " << _staticContentExchange_ServerUnit->uploadedBytes << endl;
//			stringstream ss;
//			ss << getParentModule()->getName() << " " << _staticContentExchange_ServerUnit->uploadedBytes;
//			//Debug
//			if(0 == strcmp("s1081 1147",ss.str().c_str())){
//				cout <<"AQUI"<<endl;
//			}
			bindToPort(par("port"));
			sendToUDP(newMsg, par("port"), ((StaticContentExchange_ServicePeerCommand*)this->currentRequest->getCommand())->getServeAddress(), ((StaticContentExchange_ServicePeerCommand*)this->currentRequest->getCommand())->getServePort());
			numStreams++;
			if( !(this->currentRequest->getStatus()==FAILED) ){//check if aborted
				this->currentRequest->setStatus(OK);
			}
			RequestMessage* requestMessage = new RequestMessage();
			requestMessage->setRequest(this->currentRequest);
			sendDirect(requestMessage, 0, 0, this->currentRequest->getReplyGate());
			this->currentRequest = NULL;
			this->currentObject = NULL;
			return;
		}// else {
//			processStreamRequest(msg);
//		}
	}
}
void StaticContentExchange_UDPServerHandler::finish() {
	recordScalar("streams served", numStreams);
}
int StaticContentExchange_UDPServerHandler::numInitStages() const {
	return 3;
}

bool StaticContentExchange_UDPServerHandler::isLocked() {
	return this->locked;
}
void StaticContentExchange_UDPServerHandler::lock() {
	if (this->locked) {
		throw cRuntimeError(
				"Trying to lock an already locked server handler (line: %d, file: %s)",
				__LINE__, __FILE__);
			}
			this->locked = true;
		}
void StaticContentExchange_UDPServerHandler::unlock() {
	if (!(this->locked)) {
		throw cRuntimeError(
				"Trying to unlock an already unlocked server handler (line: %d, file: %s)",
				__LINE__, __FILE__);
			}
			this->locked = false;
		}
StaticContentExchange_UDPServerHandler::StaticContentExchange_UDPServerHandler() {
	this->locked = false;
	this->currentRequest = NULL;
	this->currentObject = NULL;
	this->transportType = UDP_P;
}

StaticContentExchange_UDPServerHandler::~StaticContentExchange_UDPServerHandler() {
}

TranspotType StaticContentExchange_UDPServerHandler::getTransportType(){
	return this->transportType;
}
