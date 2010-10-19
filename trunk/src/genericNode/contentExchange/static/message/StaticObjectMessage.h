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

#ifndef STATICOBJECTMESSAGE_H
#define STATICOBJECTMESSAGE_H
#include "StaticObject.h"
#include "Request.h"
#include "StaticObjectMessage_Base_m.h"
class StaticObjectMessage : public StaticObjectMessage_Base{
	private:
		StaticObject* _object;
	public:
		StaticObjectMessage(const char *name=NULL, int kind=0) : StaticObjectMessage_Base(name,kind) {this->_object = NULL;}
		StaticObjectMessage(const StaticObjectMessage& other) : StaticObjectMessage_Base(other.getName()) {operator=(other);}
		StaticObjectMessage& operator=(const StaticObjectMessage& other) {
			StaticObjectMessage_Base::operator=(other);
			if (this!=&other){
				this->_object = other._object;
			}
			return *this;
		}
		virtual StaticObjectMessage *dup() const {return new StaticObjectMessage(*this);}

		void setObject(StaticObject* object);
		StaticObject* getObject();
		StaticObject* detachObject();
};
#endif
