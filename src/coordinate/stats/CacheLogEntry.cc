    //This file is part of CDNsim.

    //CDNsim is free software; you can redistribute it and/or modify
    //it under the terms of the GNU General Public License as published by
    //the Free Software Foundation; either version 2 of the License, or
    //(at your option) any later version.

    //CDNsim is distributed in the hope that it will be useful,
    //but WITHOUT ANY WARRANTY; without even the implied warranty of
    //MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    //GNU General Public License for more details.

    //You should have received a copy of the GNU General Public License
    //along with CDNsim; if not, write to the Free Software
    //Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

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
