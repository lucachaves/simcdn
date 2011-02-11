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
