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
