#define REQUESTMESSAGE_CC
#include "RequestMessage.h"
Register_Class(RequestMessage);

void RequestMessage::setRequest(Request* request){
	this->_request = request;
}
Request* RequestMessage::getRequest(){
	return this->_request;
}
Request* RequestMessage::detachRequest(){
	Request* request = this->_request;
	this->_request = NULL;
	return request;
}
