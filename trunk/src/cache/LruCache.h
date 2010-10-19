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

#ifndef LRUCACHE_H
#define LRUCACHE_H
#include "Cache.h"
#include "StaticObject.h"
#include <map>
#include <vector>
#include <boost/pool/pool_alloc.hpp>
/* IMPORTANT !
Every inserted object is considered to be owned by the LruCache.
LruCache simply stores the objects' pointers or returns pointers to the stored objects.
When LruCache is destroyed it destroyes every object stored.
To avoid problems just make extra copies of the objects.
*/
using namespace std;
class LruCache : public Cache{
	private:
		double _totalCapacity;
		double _availableSpace;

		map<int, StaticObject*> _cachedObjects;
		map<int, StaticObject*> objectsReferenceMap;

		vector<StaticObject*, boost::pool_allocator<StaticObject*> > _lruQueue;//_lruQueue.begin() is the oldest object
		/*
		size>0
		removes the oldest objects to make availble space equal to size
		If size > _totalCapacity then an exception is thrown
		*/
		void _freeSpace(double size);

	public:
		/*
		totalCapacity>0
		creates a new LruCache of totalCapacity capacity in bytes and loads content from file according to the objectsReference in order to get the objects' size
		*/
		LruCache(double totalCapacity, const char* cacheContents, const char* objectsReference, int shrink);
		//Every object in the _lruQueue is owned by the _lruQueue so it is deleted as well
		~LruCache();
		/*
		id>=0
		returns true if id in _lruQueue else false
		*/
		bool objectExists(int id);
		/*
		object != NULL
		Inserts a new object in _lruQueue. The object becomes newest in the _lruQueue. If the object exists then an exception is thrown. Returns a poiner to the cached object.
		If there is not enough space then the necessary space is freed
		If the object cannot fit in cache then an exception is thrown
		*/
		StaticObject* getNonExistingObject(StaticObject* object);
		/*
		id>=0
		Returns a poiner to the cached object. The requested object becomes newest in the _lruQueue
		If the object does not exist then an exception is thrown
		*/
		StaticObject* getExistingObject(int id);
		/*
		id>=0
		Returns a poiner to the object stored in the private objects reference.
		*/
		StaticObject* getObjectForced(int id);
};
#endif
