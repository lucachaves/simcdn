#define STATICOBJECT_CC
#include "StaticObject.h"
#include <assert.h>

StaticObject::StaticObject(double size, int id, int fileId){
	assert(size > 0);
	assert(id >= 0);
	this->_size = size;
	this->_id = id;
	this->_fileId = fileId;
	this->_isVolatile = true;
};
double StaticObject::getSize(){
	return this->_size;
}
int StaticObject::getId(){
	return this->_id;
}
int StaticObject::getFileId(){
	return this->_fileId;
}
StaticObject* StaticObject::clone(){
	StaticObject* cloned = new StaticObject(this->_size, this->_id, this->_fileId);

	return cloned;
}
bool StaticObject::isVolatile(){
	return this->_isVolatile;
}
void StaticObject::makeVolatile(){
	assert(!this->_isVolatile);
	this->_isVolatile = true;
}
void StaticObject::makeNonVolatile(){
	assert(this->_isVolatile);
	this->_isVolatile = false;
}
