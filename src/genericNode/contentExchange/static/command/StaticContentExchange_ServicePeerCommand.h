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
