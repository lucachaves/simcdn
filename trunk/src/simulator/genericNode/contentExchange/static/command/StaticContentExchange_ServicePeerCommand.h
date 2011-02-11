#ifndef STATICCONTENTEXCHANGESERVICEPEERCOMMAND_H
#define STATICCONTENTEXCHANGESERVICEPEERCOMMAND_H
#include "Command.h"
#include <omnetpp.h>
#include <IPAddressResolver.h>
#include "Request.h"
class StaticContentExchange_ServicePeerCommand : public Command{
	private:
		double _time;
		int _objectId;
		cGate* _serverGate;
		int _servePort;
		IPvXAddress _serveAddress;
		TranspotType _transportType;
		bool _flag;
	public:
		StaticContentExchange_ServicePeerCommand();
		~StaticContentExchange_ServicePeerCommand();

		void setTime(double time);
		double getTime();

		void setObjectId(int objectId);
		int getObjectId();

		void setServerGate(cGate* serverGate);
		cGate* getServerGate();

		void setServeAddress(IPvXAddress serveAddress);
		IPvXAddress getServeAddress();

		void setServePort(int servePort);
		int getServePort();

		void setTransportType(TranspotType transportType);
		TranspotType getTransportType();

		void setFlag(bool flag);
		bool getFlag();

};
#endif
