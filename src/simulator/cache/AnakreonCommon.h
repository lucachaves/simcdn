#ifndef ANAKREONCOMMON_H
#define ANAKREONCOMMON_H
#include <map>
using namespace std;

template <typename T1, typename T2>
struct delete_map : unary_function <void, pair<T1, T2> > {
	void operator() (pair<T1, T2> p) {
		delete p.second;
	}
};


template <typename T>
		struct delete_elem : unary_function<void, T> {
	void operator() (T* t) {
		delete t;
		t = NULL;
	}
		};


#endif
