#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "ServableItem.h"
class StaticObject : public ServableItem{
	private:
		double _size;
		int _id;
		int _fileId;
		bool _isVolatile;
	public:
		StaticObject(double size, int id, int fileId);
		double getSize();
		int getId();
		int getFileId();
		StaticObject* clone();
		bool isVolatile();
		void makeVolatile();
		void makeNonVolatile();
};
#endif
