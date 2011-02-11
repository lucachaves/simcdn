#define STATICCONTENTEXCHANGE_STATE_CC
#include "StaticContentExchange_State.h"
#include <assert.h>
#include "Exceptions.h"
StaticContentExchange_State::StaticContentExchange_State() {
	this->_cache = NULL;
	_reservedDonwloaders = 0;
	_maxDowloaders = 0;
}
Cache* StaticContentExchange_State::getCache() {
	return this->_cache;
}
void StaticContentExchange_State::setCache(Cache* cache) {
	assert(cache);
	this->_cache = cache;
}
InformationSet* StaticContentExchange_State::getInformationSet() {
	return this->_cache;
}
void StaticContentExchange_State::setInformationSet(
		InformationSet* informationSet) {
	assert(informationSet);
	this->_cache = (Cache*) informationSet;
}
void StaticContentExchange_State::registerClientHandler(
		Handler* handler) {
	assert(handler);
	this->_clientHandlers.push_back(handler);
}
void StaticContentExchange_State::registerServerHandler(
		Handler* handler) {
	assert(handler);
	this->_serverHandlers.push_back(handler);
}
StaticContentExchange_State::~StaticContentExchange_State() {
	delete this->_cache;
	this->_clientHandlers.clear();
}
bool StaticContentExchange_State::thereIsClientHandlerAvailable() {
	vector<Handler*, boost::pool_allocator<
			Handler*> >::iterator tempIterator;
	for (tempIterator = this->_clientHandlers.begin(); tempIterator
			!= this->_clientHandlers.end(); tempIterator++) {
		if (!(*tempIterator)->isLocked()) {
			return true;
		}
	}
	return false;
}
bool StaticContentExchange_State::thereIsServerHandlerAvailable() {
	vector<Handler*, boost::pool_allocator<
			Handler*> >::iterator tempIterator;
	for (tempIterator = this->_serverHandlers.begin(); tempIterator
			!= this->_serverHandlers.end(); tempIterator++) {
		if (!(*tempIterator)->isLocked()) {
			return true;
		}
	}
	return false;
}
Handler* StaticContentExchange_State::getAvailableClientHandler(TranspotType transportType) {
	//TODO TranspotType transportType
	vector<Handler*, boost::pool_allocator<
			Handler*> >::iterator tempIterator;
	for (tempIterator = this->_clientHandlers.begin(); tempIterator
			!= this->_clientHandlers.end(); tempIterator++) {
		if (!(*tempIterator)->isLocked() && (*tempIterator)->getTransportType() == transportType) {
			return (*tempIterator);
		}
	}
	throw cRuntimeError(
			"There is no available client handler (line: %d, file: %s)",
			__LINE__, __FILE__);
		}
Handler* StaticContentExchange_State::getAvailableServerHandler(TranspotType transportType) {
	//TODO TranspotType transportType
	vector<Handler*, boost::pool_allocator<
			Handler*> >::iterator tempIterator;
	for (tempIterator = this->_serverHandlers.begin(); tempIterator
			!= this->_serverHandlers.end(); tempIterator++) {
		if (!(*tempIterator)->isLocked() && (*tempIterator)->getTransportType() == transportType) {
			return (*tempIterator);
		}
	}
	throw cRuntimeError(
			"There is no available server handler (line: %d, file: %s)",
			__LINE__, __FILE__);
		}
double StaticContentExchange_State::uploadLoad() {
	if (_serverHandlers.size() == 0) {
		return 0.0;
	}
	int nLocked = 0;
	vector<Handler*, boost::pool_allocator<
			Handler*> >::iterator tempIterator;
	for (tempIterator = this->_serverHandlers.begin(); tempIterator
			!= this->_serverHandlers.end(); tempIterator++) {
		if ((*tempIterator)->isLocked()) {
			nLocked++;
		}
	}
	return (double) nLocked / (double) _serverHandlers.size();
}

Handler* StaticContentExchange_State::getClientHandler(
		int port) {
	vector<Handler*, boost::pool_allocator<
			Handler*> >::iterator tempIterator;
	for (tempIterator = this->_clientHandlers.begin(); tempIterator
			!= this->_clientHandlers.end(); tempIterator++) {
		int currentPort = (*tempIterator)->par("port");
		if (currentPort == port) {
			return (*tempIterator);
		}
	}
	throw cRuntimeError(
			"There is no client handler with port <%d> (line: %d, file: %s)",
			port, __LINE__, __FILE__);
		}
void StaticContentExchange_State::setMaxDownloaders(int maxDowloaders) {
	assert(maxDowloaders >= 0);
	this->_maxDowloaders = maxDowloaders;
}
void StaticContentExchange_State::reserveDownloader() {
	if (this->_reservedDonwloaders == this->_maxDowloaders) {
		throw cRuntimeError(
				"There is no downoader available (line: %d, file: %s)",
				__LINE__, __FILE__);
			}
			this->_reservedDonwloaders++;
		}
void StaticContentExchange_State::freeDownloader() {
	if (this->_reservedDonwloaders == 0) {
		throw cRuntimeError(
				"There is no downoader to free (line: %d, file: %s)",
				__LINE__, __FILE__);
			}
			this->_reservedDonwloaders--;
		}
bool StaticContentExchange_State::hasAvailableEphemeralPorts(TranspotType transportType) {
	double portUsage = transportType == TCP_P?tcp->ephemeralPortsUsage():udp->ephemeralPortsUsage();
	if (portUsage > 0.8) {
		return false;
	} else {
		return true;
	}
}
