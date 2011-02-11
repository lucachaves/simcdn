#ifndef INTERNODEREQUESTPROTOCOL_H
#define INTERNODEREQUESTPROTOCOL_H
#include "RequestMessage.h"
#include "Request.h"
#include "Command.h"
#include "ServableItem.h"
void decapsulateRequest_ProbagateEcho(cSimpleModule* self, Request** wrapper);
void encapuslateRequest_ProbagateCommand(cSimpleModule* self, Request* toBeEcapsulated, cGate* replyGate, cGate* targetGate);
void sendReply(cSimpleModule* self, Request* requestToReply, ServableItem* reply, RequestStatus status );
#endif
