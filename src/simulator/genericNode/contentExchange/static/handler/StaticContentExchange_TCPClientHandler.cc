#define STATICCONTENTEXCHANGE_TCPCLIENTHANDLER_CC
#include "StaticContentExchange_TCPClientHandler.h"
#include "StaticContentExchange_ServicePeer.h"
Define_Module(StaticContentExchange_TCPClientHandler);


void StaticContentExchange_TCPClientHandler::initialize(int stage)
{
	if(stage == 2){
          downloadedBytes = 0;
		StaticContentExchange_ServicePeer* staticContentExchange_ServicePeer = NULL;
		for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++){
			if (iter()->isName("staticContentExchange_ServicePeer")){
				staticContentExchange_ServicePeer = (StaticContentExchange_ServicePeer*)iter();
				break;
			}
		}
		this->_staticContentExchange_State = staticContentExchange_ServicePeer->getState();
		this->_staticContentExchange_State->registerClientHandler(this);

		socket.setOutputGate(gate("tcpOut"));
		socket.bind(IPAddressResolver().addressOf(getParentModule()), par("port"));
		socket.listen();
	}
}
int StaticContentExchange_TCPClientHandler::numInitStages() const{
	return 3;
}

void StaticContentExchange_TCPClientHandler::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
        DownloadersBase *thread = (DownloadersBase *)msg->getContextPointer();
        thread->timerExpired(msg);
    }
    else
    {
        TCPSocket *socket = socketMap.findSocketFor(msg);
        if (!socket)
        {
            // new connection -- create new socket object and server process
            socket = new TCPSocket(msg);
            socket->setOutputGate(gate("tcpOut"));

            const char *downloaderClass = par("downloaderClass");
            DownloadersBase *proc = check_and_cast<DownloadersBase *>(createOne(downloaderClass));

            socket->setCallbackObject(proc);
            proc->setup(this, socket,_staticContentExchange_State);

            socketMap.addSocket(socket);
        }
		if( socket->belongsToSocket(msg)){
				socket->processMessage(msg);
				//LUIZ permite disparar o close ao receber dados
				//if(msg->getKind() == TCP_I_DATA){
					//cout << "Close socket in client" << endl;
					//socket->close();
				//}
		}
		else{//packet from old connection?
			cerr << "WARNING ("<< simTime() << "): "<< getParentModule()->getName() <<": Old connection's packet recieved, (" << __LINE__ << ", "<< __FILE__ << ")" << endl;
			delete msg; msg = NULL;
		}
    }
}

void StaticContentExchange_TCPClientHandler::finish()
{
}

void StaticContentExchange_TCPClientHandler::removeThread(DownloadersBase *thread)
{
    // remove socket
    delete socketMap.removeSocket(thread->socket());

    // remove thread object
    delete thread;
}
bool StaticContentExchange_TCPClientHandler::isLocked(){
	return this->locked;
}
void StaticContentExchange_TCPClientHandler::lock(){
	if(this->locked){
		throw cRuntimeError("Trying to lock an already locked client handler (line: %d, file: %s)", __LINE__, __FILE__);
	}
	this->locked = true;
}
void StaticContentExchange_TCPClientHandler::unlock(){
	if(! this->locked ){
		throw cRuntimeError("Trying to unlock an already unlocked client handler (line: %d, file: %s)", __LINE__, __FILE__);
	}
	this->locked = false;
}
TranspotType StaticContentExchange_TCPClientHandler::getTransportType(){
	return this->transportType;
}

StaticContentExchange_TCPClientHandler::StaticContentExchange_TCPClientHandler(){
    this->transportType = TCP_P;
	downloadedBytes = 0;
	this->locked = false;
}
