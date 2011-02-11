#define CACHELOGENTRY_CC
#include "CacheLogEntry.h"
#include <assert.h>
Initiator CacheLogEntry::getInitiator(){
	return this->_initiator;
}
CacheStatus CacheLogEntry::getCacheStatus(){
	return this->_cacheStatus;
}

void CacheLogEntry::setInitiator(Initiator initiator){
	this->_initiator = initiator;
}
void CacheLogEntry::setCacheStatus(CacheStatus cacheStatus){
	this->_cacheStatus = cacheStatus;
}

CacheLogEntry::CacheLogEntry(){
	this->_initiator = SURROGATE;
	this->_cacheStatus = HIT;

	this->_objectId = 0;
	this->_timeStamp = 0.0;
	this->_serverName = NULL;
}

int CacheLogEntry::getObjectId(){
	return this->_objectId;
}
double CacheLogEntry::getTimeStamp(){
	return this->_timeStamp;
}
std::string* CacheLogEntry::getServerName(){
	return this->_serverName;
}

void CacheLogEntry::setObjectId(int objectId){
	this->_objectId = objectId;
}
void CacheLogEntry::setTimeStamp(double timeStamp){
	this->_timeStamp = timeStamp;
}
void CacheLogEntry::setServerName(std::string* serverName){
	assert(serverName);
	this->_serverName = serverName;
}
CacheLogEntry::~CacheLogEntry(){
	if(this->_serverName){
		delete this->_serverName; this->_serverName = NULL;
	}
}
