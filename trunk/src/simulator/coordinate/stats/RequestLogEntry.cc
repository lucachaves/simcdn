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

#define REQUESTLOGENTRY_CC
#include "RequestLogEntry.h"
#include <assert.h>
std::string* RequestLogEntry::getRequesterName(){
	return this->_requesterName;
}
Initiator RequestLogEntry::getInitiator(){
	return this->_initiator;
}
int RequestLogEntry::getObjectId(){
	return this->_objectId;
}

int RequestLogEntry::getRetries(){
	return this->_retries;
}

Status RequestLogEntry::getStatus(){
	return this->_status;
}


double RequestLogEntry::getRequestStartTime(){
	return this->_requestStartTime;
}
double RequestLogEntry::getRequestEndTime(){
	return this->_requestEndTime;
}
std::string* RequestLogEntry::getWhy(){
	return this->_why;
}

void RequestLogEntry::setRequesterName(std::string* requesterName){
	assert(requesterName);
	this->_requesterName = requesterName;
}
void RequestLogEntry::setInitiator(Initiator initiator){
	this->_initiator = initiator;
}
void RequestLogEntry::setObjectId(int objectId){
	this->_objectId = objectId;
}

void RequestLogEntry::incRetries(){
	this->_retries++;
}

void RequestLogEntry::setStatus(Status status){
	this->_status = status;
}

void RequestLogEntry::setRequestStartTime(double requestStartTime){
	this->_requestStartTime = requestStartTime;
}
void RequestLogEntry::setRequestEndTime(double requestEndTime){
	this->_requestEndTime = requestEndTime;
}
void RequestLogEntry::setWhy(std::string* who, std::string* when, std::string* why){
	assert(who);
	assert(when);
	assert(why);

	if(!this->_why){
        this->_why = new std::string();
     }
      for(std::string::iterator tempIterator = who->begin(); tempIterator != who->end(); tempIterator++ ) {
            this->_why->push_back((*tempIterator));
      }
      this->_why->push_back(' ');
      for(std::string::iterator tempIterator = when->begin(); tempIterator != when->end(); tempIterator++ ) {
            this->_why->push_back((*tempIterator));
      }
      this->_why->push_back(' ');
      for(std::string::iterator tempIterator = why->begin(); tempIterator != why->end(); tempIterator++ ) {
            this->_why->push_back((*tempIterator));
      }
      delete who; who = 0;
      delete when; when = 0;
      delete why; why = 0;
      this->_why->push_back('-');
}
void RequestLogEntry::setWhyRaw(std::string* why){
	assert(why);

	if(!this->_why){
        this->_why = new std::string();
     }
	for(std::string::iterator tempIterator = why->begin(); tempIterator != why->end(); tempIterator++ ) {
		this->_why->push_back((*tempIterator));
	}
	delete why; why = 0;
	this->_why->push_back('-');
}


RequestLogEntry::RequestLogEntry(){
	this->_requestStartTime = 0.0 ;
	this->_requestEndTime = 0.0 ;
	this->_requesterName = 0 ;
	this->_initiator = CLIENT;
	this->_objectId = 0;
	this->_retries = 0;
	this->_status = ABORTED;
	this->_why = 0;
}
RequestLogEntry::~RequestLogEntry(){
	if(this->_requesterName){
		delete this->_requesterName; this->_requesterName = NULL;
	}
	if(this->_why){
		delete this->_why; this->_why = NULL;
	}
}
void RequestLogEntry::destroyWhy(){
	if(this->_why){
		delete this->_why; this->_why = NULL;
	}
}

