#define CDN_CENTRALUNIT_REPLY_CC
#include "CDN_CentralUnit_Reply.h"
#include <assert.h>
void CDN_CentralUnit_Reply::setServerGate(cGate* serverGate){
	assert(serverGate);
	this->_serverGate = serverGate;
}
cGate* CDN_CentralUnit_Reply::getServerGate(){
	return this->_serverGate;
}
