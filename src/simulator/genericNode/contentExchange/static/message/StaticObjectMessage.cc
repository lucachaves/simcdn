#define STATICOBJECTMESSAGE_CC
#include "StaticObjectMessage.h"
Register_Class(StaticObjectMessage);

void StaticObjectMessage::setObject(StaticObject* object){
	this->_object = object;
}
StaticObject* StaticObjectMessage::getObject(){
	return this->_object;
}
StaticObject* StaticObjectMessage::detachObject(){
	StaticObject* object = this->_object;
	this->_object = NULL;
	return object;
}
