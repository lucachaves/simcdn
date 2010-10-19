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

#define StaticContentExchange_AlternateServerDetector_CC
#include "StaticContentExchange_AlternateServerDetector.h"
#include "Request.h"
#include "RequestMessage.h"
#include "CDN_CentralUnit_Reply.h"
#include "InterNodeRequestProtocol.h"
Define_Module(StaticContentExchange_AlternateServerDetector);
void StaticContentExchange_AlternateServerDetector::initialize(int stage){
	if(stage == 0){
	}
	if(stage == 1){
		for (cModule::SubmoduleIterator iter(getParentModule()->getParentModule()); !iter.end(); iter++){
			if (iter()->isName("cdn_CentralUnit")){
				this->_cdn_CentralUnit = (CDN_CentralUnit*)iter();
				break;
			}
		}
	}
}
int StaticContentExchange_AlternateServerDetector::numInitStages() const{
	return 3;
}
void StaticContentExchange_AlternateServerDetector::handleMessage(cMessage *msg){
	if(msg->arrivedOn("fromClientUnit")){
		this->handleFromClientUnitMessage(msg);
	}
	else if(msg->arrivedOn("fromCentralUnit")){
		this->handleFromCentralUnitMessage(msg);
	}
}
void StaticContentExchange_AlternateServerDetector::finish(){
}
void StaticContentExchange_AlternateServerDetector::handleFromClientUnitMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	encapuslateRequest_ProbagateCommand(this, originalRequest, this->gate("fromCentralUnit"),this->_cdn_CentralUnit->gate("fromAlternateServerDetector"));
}
void StaticContentExchange_AlternateServerDetector::handleFromCentralUnitMessage(cMessage *msg){
	Request* originalRequest = ((RequestMessage*)msg)->detachRequest(); //detach the original-request
	delete msg; msg = NULL;

	originalRequest->getNext()->setReply( originalRequest->getReply() );
	decapsulateRequest_ProbagateEcho(this, &originalRequest);
}
