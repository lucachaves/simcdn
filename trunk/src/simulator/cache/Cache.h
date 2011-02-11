#ifndef CACHE_H
#define CACHE_H
#include "InformationSet.h"
#include "StaticObject.h"

class Cache : public InformationSet{
	public:
		Cache();
		virtual bool objectExists(int id) = 0;
		virtual ~Cache();
		virtual StaticObject* getNonExistingObject(StaticObject* object) = 0;
		virtual StaticObject* getExistingObject(int id) = 0;
		virtual StaticObject* getObjectForced(int id) = 0;
};
#endif
