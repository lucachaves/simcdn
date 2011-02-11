#ifndef LFUCACHE_H
#define LFUCACHE_H
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
class LfuCache : public Cache{
	private:
		double _totalCapacity;
		double _availableSpace;

		map<int, StaticObject*> _cachedObjects;
		map<int, StaticObject*> objectsReferenceMap;
		map<int, int> _useObjects;

		vector<StaticObject*, boost::pool_allocator<StaticObject*> > _lfuQueue;//_lruQueue.begin() is the oldest object
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
		LfuCache(double totalCapacity, const char* cacheContents, const char* objectsReference, int shrink);
		//Every object in the _lruQueue is owned by the _lruQueue so it is deleted as well
		~LfuCache();
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
