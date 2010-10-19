#include "DownloadersBase.h"
#include "Request.h"
#include "RequestMessage.h"
#include "StaticContentExchange_ServicePeer.h"
#include "Exceptions.h"
#include "StaticObjectMessage.h"
#include <assert.h>
Register_Class(DownloadersBase);
void DownloadersBase::setup(StaticContentExchange_TCPClientHandler *hostmodule, TCPSocket *socket, StaticContentExchange_State* staticContentExchange_State){
	hostmod=hostmodule;
	sock=socket;
	_staticContentExchange_State = staticContentExchange_State;
}

void DownloadersBase::socketDataArrived(int, void *, cPacket *msg, bool urgent){
	dataArrived(msg,urgent);
}
void DownloadersBase::socketEstablished(int, void *){
	established();
}
void DownloadersBase::socketPeerClosed(int, void *){
	peerClosed();
}
void DownloadersBase::socketClosed(int, void *){
	closed();
}
void DownloadersBase::socketFailure(int, void *, int code){
	failure(code);
}
void DownloadersBase::socketStatusArrived(int, void *, TCPStatusInfo *status) {
	statusArrived(status);
}

DownloadersBase::DownloadersBase()  {
	sock=NULL;
}
DownloadersBase::~DownloadersBase() {
}



TCPSocket* DownloadersBase::socket() {
	return sock;
}

StaticContentExchange_TCPClientHandler* DownloadersBase::hostModule() {
	return hostmod;
}

void DownloadersBase::scheduleAt(simtime_t t, cMessage *msg)  {
	msg->setContextPointer(this);
	hostmod->scheduleAt(t,msg);
}


void DownloadersBase::cancelEvent(cMessage *msg)  {
	hostmod->cancelEvent(msg);
}


simtime_t DownloadersBase::simTime() {
	return simTime();
}


void DownloadersBase::established(){
	//cout << "INFO ("<< simTime() << "): "<< hostModule()->getParentModule()->getName() <<": Connection established, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
}


void DownloadersBase::dataArrived(cPacket *msg, bool urgent){
	//if(!data_arrived){data_arrived = true; cout << "DATA" << endl;}
	//else{msg = NULL; return; cout << "DUBLICATE DATA" << endl;} //WE MUST NOT DELETE msg BECAUSE THE POINTER POINT IN CACHE!!!
	//cout << "INFO ("<< simTime() << "): "<< hostModule()->getParentModule()->getName() <<": Recieved data, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
     assert(hostModule());
     hostModule()->downloadedBytes += msg->getByteLength();
     //Luiz cout << "UTIL_DOWN "<< simTime() << " "<< hostModule()->getParentModule()->getName() <<" " << hostModule()->downloadedBytes << endl;
     cout << "UTIL_DOWN "<< cSimulation::getActiveSimulation()->getSimTime() << " "<< hostModule()->getParentModule()->getName() <<" " << hostModule()->downloadedBytes << endl;
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
	delete msg; msg = NULL;
	//cout << "INFO ("<< simTime() << "): "<< hostModule()->getParentModule()->getName() <<": Closing, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
	socket()->close();
}


void DownloadersBase::timerExpired(cMessage *timer){
	delete timer; timer = NULL;
	hostmod->removeThread(this);
}


void DownloadersBase::peerClosed() {
	//cout << "INFO ("<< simTime() << "): "<< hostModule()->getParentModule()->getName() <<": Peer closed, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
}


void DownloadersBase::closed() {
	//cout << "INFO ("<< simTime() << "): "<< hostModule()->getParentModule()->getName() <<": Socket closed, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
	hostmod->removeThread(this);
}


void DownloadersBase::failure(int code) {
	cerr << "WARNING ("<< simTime() << "): "<< hostModule()->getParentModule()->getName() <<": SOCKERROR, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
	socket()->abort();
	return;
}

void DownloadersBase::statusArrived(TCPStatusInfo *status) {
	delete status; status = NULL;
}
