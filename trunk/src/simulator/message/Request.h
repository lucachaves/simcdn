#ifndef REQUEST_H
#define REQUEST_H
#include "ServableItem.h"
#include "Command.h"
#include <omnetpp.h>
#include "RequestLogEntry.h"
using namespace std;
enum RequestStatus {OK, FAILED, UNKNOWN};
enum TranspotType {TCP_P, UDP_P, UNKNOWN_P};
class Request{
	private:
		Command* _command;
		Request* _next;
		ServableItem* _reply;
		cGate* _replyGate;
		RequestStatus _status;
		TranspotType _transportType;
		RequestLogEntry* _requestLogEntry;

	public:
		//getters
		Command* getCommand();
		Request* getNext();
		ServableItem* getReply();
		cGate* getReplyGate();
		RequestStatus getStatus();
		RequestLogEntry* getRequestLogEntry();
		TranspotType getTransportType();

		//setters
		Request();
		void setCommand(Command* command);
		void setNext(Request *next);
		void setReply(ServableItem* reply);
		void setReplyGate(cGate* gate);
		void setStatus(RequestStatus status);
		void setRequestLogEntry(RequestLogEntry* requestLogEntry);
		void setTransportType(TranspotType transportType);

		//Detachers
		Command* detachCommand(); //make pointer NULL and returns the pointer (before become NULL)
		Request* detachNext(); //make pointer NULL and returns the pointer (before become NULL)
		ServableItem* detachReply(); //make pointer NULL and returns the pointer (before become NULL)
		RequestLogEntry* detachRequestLogEntry();
		void clear(); //will not delete anything. It will detach everything and return nothing

		//Destory
		void destroyAll(); //will delete everything recursivelly. You detach everything necessary before delete.
		~Request(); // will delete everything recursivelly. You detach everything necessary before delete.

};

#endif
