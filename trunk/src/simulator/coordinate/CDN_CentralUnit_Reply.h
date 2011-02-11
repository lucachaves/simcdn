#ifndef CDN_CENTRALUNIT_REPLY_H
#define CDN_CENTRALUNIT_REPLY_H
#include "ServableItem.h"
#include <omnetpp.h>
class CDN_CentralUnit_Reply : public ServableItem{
	protected:
		cGate* _serverGate;
	public:
		void setServerGate(cGate* serverGate);
		cGate* getServerGate();
};
#endif
