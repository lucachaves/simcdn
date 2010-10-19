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

#define INTERNODEREQUESTPROTOCOL_CC
#include "InterNodeRequestProtocol.h"
#include <omnetpp.h>
#include <assert.h>
#include "RequestLogEntry.h"
#include <omnetpp.h>
void decapsulateRequest_ProbagateEcho(cSimpleModule* self, Request** wrapper){
	assert(self);
	assert(wrapper);
	assert(*wrapper);

	if( (*wrapper)->getNext() ){
		(*wrapper)->detachCommand();
		Request* encapsulated = (*wrapper)->detachNext();
		encapsulated->setRequestLogEntry((*wrapper)->detachRequestLogEntry());


		encapsulated->setStatus((*wrapper)->getStatus());
		(*wrapper)->detachReply();

		RequestMessage* requestMessage = new RequestMessage();
		requestMessage->setRequest(encapsulated);
		self->sendDirect(requestMessage, 0, 0, encapsulated->getReplyGate());
	}
	delete (*wrapper);
	(*wrapper) = NULL;
}
void encapuslateRequest_ProbagateCommand(cSimpleModule* self, Request* toBeEcapsulated, cGate* replyGate, cGate* targetGate){
	assert(self);
	assert(toBeEcapsulated);
	assert(replyGate);
	assert(targetGate);

	Request* request = new Request();
	request->setCommand( toBeEcapsulated->getCommand() ); // Watch out for accidental deletion!
	request->setNext(toBeEcapsulated); //encapsulate the originalRequest for future reference
	request->setRequestLogEntry(toBeEcapsulated->getRequestLogEntry());
	request->setReplyGate(replyGate);
	request->setTransportType(toBeEcapsulated->getTransportType());

	RequestMessage* requestMessage = new RequestMessage();
	requestMessage->setRequest(request);

	//ev << "FROM " << replyGate->getOwnerModule()->getName() << " TO " << targetGate->getOwnerModule()->getName() << endl;

	//ev << self->sendDirect(requestMessage, 0, targetGate) << endl;
	self->sendDirect(requestMessage, 0, 0, targetGate);
}

void sendReply(cSimpleModule* self, Request* requestToReply, ServableItem* reply, RequestStatus status ){
	assert(self);
	assert(requestToReply);

	requestToReply->setReply(reply);
	requestToReply->setStatus(OK);

	RequestMessage* requestMessage = new RequestMessage();
	requestMessage->setRequest(requestToReply);

	self->sendDirect(requestMessage, 0, 0, requestToReply->getReplyGate());
}
