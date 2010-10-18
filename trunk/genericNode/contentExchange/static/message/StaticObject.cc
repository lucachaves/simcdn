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
