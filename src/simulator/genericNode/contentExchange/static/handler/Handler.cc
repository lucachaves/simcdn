#define HANDLER_CC
#include "Handler.h"
Define_Module(Handler);
Handler::Handler(){
}

Handler::~Handler(){
}

bool Handler::isLocked(){
	return true;
}

void Handler::unlock(){}

void Handler::lock(){}

TranspotType Handler::getTransportType(){
	return UNKNOWN_P;
}
