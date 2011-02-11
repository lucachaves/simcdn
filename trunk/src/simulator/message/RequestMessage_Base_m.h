//
// Generated file, do not edit! Created by opp_msgc 4.1 from src/simulator/message/RequestMessage_Base.msg.
//

#ifndef _REQUESTMESSAGE_BASE_M_H_
#define _REQUESTMESSAGE_BASE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>src/simulator/message/RequestMessage_Base.msg</tt> by opp_msgc.
 * <pre>
 * packet RequestMessage
 * {
 *     @customize(true);
 * }
 * </pre>
 *
 * RequestMessage_Base is only useful if it gets subclassed, and RequestMessage is derived from it.
 * The minimum code to be written for RequestMessage is the following:
 *
 * <pre>
 * class RequestMessage : public RequestMessage_Base
 * {
 *   public:
 *     RequestMessage(const char *name=NULL, int kind=0) : RequestMessage_Base(name,kind) {}
 *     RequestMessage(const RequestMessage& other) : RequestMessage_Base(other.getName()) {operator=(other);}
 *     RequestMessage& operator=(const RequestMessage& other) {RequestMessage_Base::operator=(other); return *this;}
 *     virtual RequestMessage *dup() const {return new RequestMessage(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from RequestMessage_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(RequestMessage);
 * </pre>
 */
class RequestMessage_Base : public ::cPacket
{
  protected:

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RequestMessage_Base&);
    // make constructors protected to avoid instantiation
    RequestMessage_Base(const char *name=NULL, int kind=0);
    RequestMessage_Base(const RequestMessage_Base& other);
    // make assignment operator protected to force the user override it
    RequestMessage_Base& operator=(const RequestMessage_Base& other);

  public:
    virtual ~RequestMessage_Base();
    virtual RequestMessage_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class RequestMessage");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};


#endif // _REQUESTMESSAGE_BASE_M_H_
