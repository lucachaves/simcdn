#ifndef STATE_H
#define STATE_H
#include "InformationSet.h"
class State{
	protected:
		InformationSet* _informationSet;
	public:
		virtual InformationSet* getInformationSet()=0;
		virtual void setInformationSet(InformationSet* informationSet)=0;
		virtual ~State(){}

};
#endif
