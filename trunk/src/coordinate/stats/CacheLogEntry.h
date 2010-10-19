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

#ifndef CACHELOGENTRY_H
#define CACHELOGENTRY_H
#include "LogEntry.h"
#include <string>
enum CacheStatus{HIT, MISS};
class CacheLogEntry : public LogEntry{
private:
	Initiator _initiator;
	CacheStatus _cacheStatus;
	int _objectId;
	double _timeStamp;
	std::string* _serverName;

public:
	Initiator getInitiator();
	CacheStatus getCacheStatus();

	int getObjectId();
	double getTimeStamp();
	std::string*  getServerName();

	void setInitiator(Initiator initiator);
	void setCacheStatus(CacheStatus cacheStatus);

	void setObjectId(int objectId);
	void setTimeStamp(double timeStamp);
	void setServerName(std::string* serverName); //copies
	CacheLogEntry();
	~CacheLogEntry();
};
#endif
