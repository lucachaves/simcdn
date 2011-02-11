#ifndef STATICCONTENTEXCHANGE_ALTERNATESERVERDETECTOR_H
#define STATICCONTENTEXCHANGE_ALTERNATESERVERDETECTOR_H
#include "AlternateServerDetector.h"
#include "CDN_CentralUnit.h"
class CDN_CentralUnit;
class StaticContentExchange_AlternateServerDetector : public AlternateServerDetector{
	protected:
		CDN_CentralUnit* _cdn_CentralUnit;

		void initialize(int stage);
		int numInitStages() const;
		void handleMessage(cMessage *msg);
		void finish();
		void handleFromClientUnitMessage(cMessage *msg);
		void handleFromCentralUnitMessage(cMessage *msg);
};
#endif
