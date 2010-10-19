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

#define STATICCONTENTEXCHANGESERVICEPEERCOMMAND_CC
#include "StaticContentExchange_ServicePeerCommand.h"
#include <assert.h>
StaticContentExchange_ServicePeerCommand::StaticContentExchange_ServicePeerCommand(){
	this->_objectId = -1;
	this->_time = -1.0;
	this->_serverGate = NULL;
	this->_servePort = -1;
	this->_transportType = UNKNOWN_P;
	this->_flag = false;
}
StaticContentExchange_ServicePeerCommand::~StaticContentExchange_ServicePeerCommand(){
}
void StaticContentExchange_ServicePeerCommand::setTime(double time){
	assert(time >= 0.0);
	this->_time = time;
}
void StaticContentExchange_ServicePeerCommand::setObjectId(int objectId){
	assert(objectId >= 0);
	this->_objectId = objectId;
}
double StaticContentExchange_ServicePeerCommand::getTime(){
	return this->_time;
}
int StaticContentExchange_ServicePeerCommand::getObjectId(){
	return this->_objectId;
}
void StaticContentExchange_ServicePeerCommand::setServerGate(cGate* serverGate){
	assert(serverGate);
	this->_serverGate = serverGate;
}
cGate* StaticContentExchange_ServicePeerCommand::getServerGate(){
	return this->_serverGate;
}
void StaticContentExchange_ServicePeerCommand::setServeAddress(IPvXAddress serveAddress){
	this->_serveAddress = serveAddress;
}
IPvXAddress StaticContentExchange_ServicePeerCommand::getServeAddress(){
	return this->_serveAddress;
}
void StaticContentExchange_ServicePeerCommand::setServePort(int servePort){
	this->_servePort = servePort;
}
int StaticContentExchange_ServicePeerCommand::getServePort(){
	return this->_servePort;
}
void StaticContentExchange_ServicePeerCommand::setTransportType(TranspotType transportType){
	this->_transportType = transportType;
}
TranspotType StaticContentExchange_ServicePeerCommand::getTransportType(){
	return this->_transportType;
}

void StaticContentExchange_ServicePeerCommand::setFlag(bool flag){
	this->_flag = flag;
}
bool StaticContentExchange_ServicePeerCommand::getFlag(){
	return this->_flag;
}
