#include <omnetpp.h>
#include "Exceptions.h"
double gimmeport(double totalHandlers){
	if(totalHandlers - 1000.0 > 65535){
		throw new MaxHandlersLimitExceededException();
	}
	static double port = 1000.0;
	if(port - 1000.0 > totalHandlers ){port = 1000.0;}
	port++;
	return port;
}
Define_Function(gimmeport, 1);
