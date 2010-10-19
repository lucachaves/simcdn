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

#define REQUEST_CC
#include "Request.h"
#include <assert.h>
Request::Request(){
	this->_next = NULL;
	this->_reply = NULL;
	this->_replyGate = NULL;
	this->_status = UNKNOWN;
	this->_requestLogEntry = NULL;
}
Request::~Request(){
	this->destroyAll();
}
Command* Request::getCommand(){
	return this->_command;
}
void Request::setCommand(Command* command){
	this->_command = command;
}
Request* Request::getNext(){
	return this->_next;
}
void Request::setNext(Request *next){
	this->_next = next;
}
ServableItem* Request::getReply(){
	return this->_reply;
}
void Request::setReply(ServableItem* reply){
	this->_reply = reply;
}
cGate* Request::getReplyGate(){
	return this->_replyGate;
}
void Request::setReplyGate(cGate* gate){
	assert(gate);
	this->_replyGate = gate;
}
RequestStatus Request::getStatus(){
	return this->_status;
}
void Request::setStatus(RequestStatus status){
	this->_status = status;
}
TranspotType Request::getTransportType(){
	return this->_transportType;
}
void Request::setTransportType(TranspotType transportType){
	this->_transportType = transportType;
}
Command* Request::detachCommand(){
	Command* command = this->_command;
	this->_command = NULL;
	return command;
}
Request* Request::detachNext(){
	Request* next = this->_next;
	this->_next = NULL;
	return next;
}
ServableItem* Request::detachReply(){
	ServableItem* reply = this->_reply;
	this->_reply = NULL;
	return reply;
}
void Request::clear(){
	this->detachNext();
	this->detachReply();
	this->_replyGate = NULL;
	this->_status = UNKNOWN;
}
void Request::destroyAll(){
	if(this->_command){
		delete this->_command;
	}
	if(this->_next){
		delete this->_next;
	}
	if(this->_reply){
		delete this->_reply;
	}
	this->_replyGate = NULL;
	this->_status = UNKNOWN;
	if(this->_requestLogEntry){
		delete this->_requestLogEntry; this->_requestLogEntry = NULL;
	}
}
RequestLogEntry* Request::getRequestLogEntry(){
	return this->_requestLogEntry;
}
void Request::setRequestLogEntry(RequestLogEntry* requestLogEntry){
	assert(requestLogEntry);
	this->_requestLogEntry = requestLogEntry;
}
RequestLogEntry* Request::detachRequestLogEntry(){
	RequestLogEntry* temp = this->_requestLogEntry;
	this->_requestLogEntry = NULL;
	return temp;
}
