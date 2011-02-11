#ifndef REQUESTMESSAGE_H
#define REQUESTMESSAGE_H
#include "RequestMessage_Base_m.h"
#include "Request.h"
class RequestMessage : public RequestMessage_Base{
	private:
		Request* _request;
	public:
		RequestMessage(const char *name=NULL, int kind=0) : RequestMessage_Base(name,kind) {this->_request = NULL;}
		RequestMessage(const RequestMessage& other) : RequestMessage_Base(other.getName()) {operator=(other);}
		RequestMessage& operator=(const RequestMessage& other) {
			RequestMessage_Base::operator=(other);
			if (this!=&other){
				this->_request = other._request;
			}
			return *this;
		}
		virtual RequestMessage *dup() const {return new RequestMessage(*this);}

		void setRequest(Request* request);
		Request* getRequest();
		Request* detachRequest();
};
#endif
