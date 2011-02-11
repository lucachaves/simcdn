#define MRUCACHE_CC
#include "MruCache.h"
#include <assert.h>
#include <algorithm>
#include "AnakreonCommon.h"
#include "Exceptions.h"
#include <omnetpp.h>
MruCache::MruCache(double totalCapacity, const char* cacheContents, const char* objectsReference, int shrink){
	assert(totalCapacity >= 0);
	this->_totalCapacity = totalCapacity;
	this->_availableSpace = totalCapacity;

	if(!strcmp(cacheContents, "NULL")){
		return;
	}
	char line[1024];
	int objectId = -1;
	char isVolatile = 's';
	int fileId = -1;
	///////////////////////////////////////////////////
	FILE* objectsReferenceFile = fopen(objectsReference,"r");
	if(!objectsReferenceFile){
		throw cRuntimeError("Unable to read file <%s> (line: %d, file: %s)", objectsReference, __LINE__, __FILE__);
	}
	double size = -1.0;
	while ( fgets( line, 1024, objectsReferenceFile )){
		if ( 3 != sscanf( line, "%d %lf %d", &objectId, &size, &fileId) ){
			throw cRuntimeError("Invlaid objects file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
		}

		if (objectId < 0 || size < 0.0 || fileId < 0){
			throw cRuntimeError("Invlaid objects file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
		}
		objectsReferenceMap.insert(make_pair(objectId, new StaticObject(size, objectId, fileId)));
	}
	fclose(objectsReferenceFile);
	///////////////////////////////////////////////////


	///////////////////////////////////////////////////
	FILE* cacheContentsFile = fopen(cacheContents,"r");
	if(!cacheContentsFile){
		throw cRuntimeError("Unable to read file <%s> (line: %d, file: %s)", cacheContents, __LINE__, __FILE__);
	}

	while ( fgets( line, 1024, cacheContentsFile )){
		if( 2 == sscanf( line, "%d %c", &objectId, &isVolatile ) ){

			if(isVolatile == 'v'){
				map<int, StaticObject*> ::iterator mapPos = objectsReferenceMap.find(objectId);
				if(mapPos == objectsReferenceMap.end()){
					throw cRuntimeError("Unable to find object <%d> while loading objects (line: %d, file: %s)", objectId, __LINE__, __FILE__);
				}
				StaticObject* newObj = (*mapPos).second->clone();
				this->_cachedObjects.insert(make_pair(objectId, newObj));
				this->_availableSpace -= objectsReferenceMap[objectId]->getSize();
				this->_mruQueue.push_back(newObj);
			}
			else{
				if(isVolatile == 's'){
					map<int, StaticObject*> ::iterator mapPos = objectsReferenceMap.find(objectId);
					if(mapPos == objectsReferenceMap.end()){
						throw cRuntimeError("Unable to find object <%d> while loading objects (line: %d, file: %s)", objectId, __LINE__, __FILE__);
					}
					StaticObject* newObj = (*mapPos).second->clone();
					newObj->makeNonVolatile();
					this->_cachedObjects.insert(make_pair(objectId, newObj));
					this->_availableSpace -= objectsReferenceMap[objectId]->getSize();
				}else{
					throw cRuntimeError("Invlaid cache file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
				}
			}
		}
		else{
			if ( 1 == sscanf( line, "%d", &objectId ) ){
				map<int, StaticObject*> ::iterator mapPos = objectsReferenceMap.find(objectId);
				if(mapPos == objectsReferenceMap.end()){
					throw cRuntimeError("Unable to find object <%d> while loading objects (line: %d, file: %s)", objectId, __LINE__, __FILE__);
				}
				StaticObject* newObj = (*mapPos).second->clone();
				this->_cachedObjects.insert(make_pair(objectId, newObj));
				this->_availableSpace -= objectsReferenceMap[objectId]->getSize();
				this->_mruQueue.push_back(newObj);
			}
			else{
				throw cRuntimeError("Invlaid objects file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
			}
		}
	}
	if(this->_availableSpace < 0){
		throw cRuntimeError("Cache content file objects exceed the capacity (line: %d, file: %s)", __LINE__, __FILE__);
	}
	fclose(cacheContentsFile);

	if (shrink == 1){
		this->_totalCapacity = this->_totalCapacity - this->_availableSpace;
		this->_availableSpace = 0;
	}
	//////////////////////////////////////////////////
}
void MruCache::_freeSpace(double size){
	assert(size > 0);
	if(size > this->_totalCapacity){
		throw cRuntimeError("size to free > total capacity (line: %d, file: %s)",  __LINE__, __FILE__);
	}
	while(size > 0){
		if ( this->_mruQueue.size() == 0){
			throw cRuntimeError("Empty lru while still removing objects (line: %d, file: %s)",  __LINE__, __FILE__);
		}

		map<int, StaticObject*>::iterator mapPos;
		vector<StaticObject*, boost::pool_allocator<StaticObject*> >::iterator vecPos;

		mapPos = this->_cachedObjects.find(this->_mruQueue.back()->getId());
		vecPos = this->_mruQueue.end();

		size -= this->_mruQueue.back()->getSize();
		_availableSpace += this->_mruQueue.back()->getSize();

		delete (*mapPos).second;
		this->_cachedObjects.erase(mapPos);
		this->_mruQueue.erase(vecPos);
	}
}
MruCache::~MruCache(){
	for_each(this->_cachedObjects.rbegin(), this->_cachedObjects.rend(), delete_map<int, StaticObject*>());
	this->_cachedObjects.clear();
	this->_mruQueue.clear();
}
bool MruCache::objectExists(int id){
	assert(id>=0);
	return (this->_cachedObjects.find(id) != this->_cachedObjects.end());
}
StaticObject* MruCache::getNonExistingObject(StaticObject* object){
	assert(object);
	if(this->objectExists(object->getId())){
		delete object; object = NULL;
		throw new ObjectAlreadyExistsException();
	}
	if(object->getSize() > this->_totalCapacity){
		delete object; object = NULL;
		throw new ObjectTooBigException();
	}

	double lruCacheSize = 0;
	for(vector<StaticObject*, boost::pool_allocator<StaticObject*> >::iterator tempIterator = this->_mruQueue.begin(); tempIterator != this->_mruQueue.end(); tempIterator++ ) {
		lruCacheSize += (*tempIterator)->getSize();
	}
	if ( lruCacheSize < ( object->getSize() - this->_availableSpace) ){
		delete object; object = NULL;
		throw new ObjectTooBigException();
	}

	if(this->_availableSpace < object->getSize()){
		this->_freeSpace(object->getSize() - this->_availableSpace);
	}
	//make it volatile
	if(!object->isVolatile()){
		object->makeVolatile();
	}
	this->_cachedObjects.insert(make_pair(object->getId(),object));
	this->_mruQueue.push_back(object);
	this->_availableSpace -= object->getSize();
	return object;
}
StaticObject* MruCache::getExistingObject(int id){
	assert(id>=0);
	if(!this->objectExists(id)){
		throw new ObjectDoesNotExistException();
	}
	StaticObject* objectInMap = this->_cachedObjects[id];
	if(!objectInMap->isVolatile()){
		return objectInMap;
	}
	else{
		for(vector<StaticObject*, boost::pool_allocator<StaticObject*> >::iterator tempIterator = this->_mruQueue.begin(); tempIterator != this->_mruQueue.end(); tempIterator++ ) {
			if((*tempIterator)->getId() == id){
				StaticObject* object = *tempIterator; // get the object reference
				this->_mruQueue.erase(tempIterator);
				this->_mruQueue.push_back(object);
				return object;
			}
		}
	}
	throw new ObjectDoesNotExistException();
}
StaticObject* MruCache::getObjectForced(int id){
	return this->objectsReferenceMap[id];
}
