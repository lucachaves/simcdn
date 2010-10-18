#
# OMNeT++/OMNEST Makefile for CDNRef
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I../inet/src/networklayer/rsvp_te -I../inet/src/networklayer/common -I../inet/src/networklayer/icmpv6 -I../inet/src/transport/tcp -I../inet/src/networklayer/mpls -I../inet/src/networklayer/ted -I../inet/src/networklayer/contract -I../inet/src/util -I../inet/src/transport/contract -I../inet/src/linklayer/mfcore -I../inet/src/networklayer/ldp -I../inet/src/networklayer/ipv4 -I../inet/src/base -I../inet/src/util/headerserializers -I../inet/src/networklayer/ipv6 -I../inet/src/transport/sctp -I../inet/src/world -I../inet/src/applications/pingapp -I../inet/src/linklayer/contract -I../inet/src/networklayer/arp -I../inet/src/transport/udp -L../inet/out/$(CONFIGNAME)/src -linet -KINET_PROJ=../inet
#

# Name of target to be created (-o option)
TARGET = CDNRef$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../inet/src/networklayer/rsvp_te \
    -I../inet/src/networklayer/common \
    -I../inet/src/networklayer/icmpv6 \
    -I../inet/src/transport/tcp \
    -I../inet/src/networklayer/mpls \
    -I../inet/src/networklayer/ted \
    -I../inet/src/networklayer/contract \
    -I../inet/src/util \
    -I../inet/src/transport/contract \
    -I../inet/src/linklayer/mfcore \
    -I../inet/src/networklayer/ldp \
    -I../inet/src/networklayer/ipv4 \
    -I../inet/src/base \
    -I../inet/src/util/headerserializers \
    -I../inet/src/networklayer/ipv6 \
    -I../inet/src/transport/sctp \
    -I../inet/src/world \
    -I../inet/src/applications/pingapp \
    -I../inet/src/linklayer/contract \
    -I../inet/src/networklayer/arp \
    -I../inet/src/transport/udp \
    -I. \
    -Icache \
    -Icoordinate \
    -Icoordinate/command \
    -Icoordinate/stats \
    -Iexecption \
    -IgenericNode \
    -IgenericNode/contentExchange \
    -IgenericNode/contentExchange/static \
    -IgenericNode/contentExchange/static/command \
    -IgenericNode/contentExchange/static/handler \
    -IgenericNode/contentExchange/static/message \
    -IgenericNode/contentExchange/static/state \
    -Imessage \
    -Imodels \
    -Imodels/RNP \
    -Imodels/RNP/caches \
    -Imodels/RNP/dataset \
    -Imodels/RNP/results \
    -Imodels/RNP/stats \
    -Imodels/RNP_LAYOUT_1 \
    -Imodels/RNP_LAYOUT_2 \
    -Imodels/_batch \
    -Imodels/_stats \
    -Imodels/exp01 \
    -Imodels/exp01/caches \
    -Imodels/exp01/dataset \
    -Imodels/exp01/results \
    -Imodels/exp01/stats \
    -Imodels/exp02 \
    -Imodels/exp02/caches \
    -Imodels/exp02/dataset \
    -Imodels/exp02/stats \
    -Imodels/exp11 \
    -Imodels/exp11/caches \
    -Imodels/exp11/dataset \
    -Imodels/exp11/results \
    -Imodels/exp11/stats \
    -Imodels/exp12 \
    -Imodels/exp12/caches \
    -Imodels/exp12/dataset \
    -Imodels/exp12/results \
    -Imodels/exp12/stats \
    -Imodels/nHost \
    -Imodels/nHost/caches \
    -Imodels/nHost/dataset \
    -Imodels/nHost/results \
    -Imodels/nHost/stats \
    -Imodels/simpleCDN \
    -Imodels/simpleCDN/caches \
    -Imodels/simpleCDN/dataset \
    -Imodels/simpleCDN/results \
    -Imodels/simpleCDN/stats \
    -Imodels/teste \
    -Imodels/teste/caches \
    -Imodels/teste/dataset \
    -Imodels/teste/results \
    -Imodels/teste/stats

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../inet/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath ../inet/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/cache/Cache.o \
    $O/cache/LfuCache.o \
    $O/cache/MruCache.o \
    $O/cache/LruCache.o \
    $O/cache/InformationSet.o \
    $O/coordinate/CDN_RequestsAssignerReceiver.o \
    $O/coordinate/CDN_CentralUnit.o \
    $O/coordinate/CentralUnit.o \
    $O/coordinate/CDN_CentralUnit_Reply.o \
    $O/coordinate/command/Commands.o \
    $O/coordinate/command/CDN_Commands.o \
    $O/coordinate/stats/statistic.o \
    $O/coordinate/stats/CacheLogEntry.o \
    $O/coordinate/stats/RequestLogEntry.o \
    $O/coordinate/stats/Stats.o \
    $O/genericNode/PortNumberAllocator.o \
    $O/genericNode/contentExchange/Negotiator.o \
    $O/genericNode/contentExchange/AlternateServerDetector.o \
    $O/genericNode/contentExchange/ServerUnit.o \
    $O/genericNode/contentExchange/ServicePeer.o \
    $O/genericNode/contentExchange/ClientUnit.o \
    $O/genericNode/contentExchange/RequestsAssignerReceiver.o \
    $O/genericNode/contentExchange/StateTester.o \
    $O/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o \
    $O/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o \
    $O/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o \
    $O/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o \
    $O/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o \
    $O/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o \
    $O/genericNode/contentExchange/static/StaticContentExchange_StateTester.o \
    $O/genericNode/contentExchange/static/command/Command.o \
    $O/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o \
    $O/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o \
    $O/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o \
    $O/genericNode/contentExchange/static/handler/DownloadersBase.o \
    $O/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o \
    $O/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o \
    $O/genericNode/contentExchange/static/handler/Handler.o \
    $O/genericNode/contentExchange/static/message/StaticObject.o \
    $O/genericNode/contentExchange/static/message/ServableItem.o \
    $O/genericNode/contentExchange/static/message/StaticObjectMessage.o \
    $O/genericNode/contentExchange/static/state/StaticContentExchange_State.o \
    $O/genericNode/contentExchange/static/state/State.o \
    $O/message/RequestMessage.o \
    $O/message/Request.o \
    $O/message/InterNodeRequestProtocol.o \
    $O/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o \
    $O/message/RequestMessage_Base_m.o

# Message files
MSGFILES = \
    genericNode/contentExchange/static/message/StaticObjectMessage_Base.msg \
    message/RequestMessage_Base.msg

# Other makefile variables (-K)
INET_PROJ=../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET)

$(TARGET) : $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY:

.SUFFIXES: .cc

$O/%.o: %.cc
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f CDNRef CDNRef.exe libCDNRef.so libCDNRef.a libCDNRef.dll libCDNRef.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f cache/*_m.cc cache/*_m.h
	-rm -f coordinate/*_m.cc coordinate/*_m.h
	-rm -f coordinate/command/*_m.cc coordinate/command/*_m.h
	-rm -f coordinate/stats/*_m.cc coordinate/stats/*_m.h
	-rm -f execption/*_m.cc execption/*_m.h
	-rm -f genericNode/*_m.cc genericNode/*_m.h
	-rm -f genericNode/contentExchange/*_m.cc genericNode/contentExchange/*_m.h
	-rm -f genericNode/contentExchange/static/*_m.cc genericNode/contentExchange/static/*_m.h
	-rm -f genericNode/contentExchange/static/command/*_m.cc genericNode/contentExchange/static/command/*_m.h
	-rm -f genericNode/contentExchange/static/handler/*_m.cc genericNode/contentExchange/static/handler/*_m.h
	-rm -f genericNode/contentExchange/static/message/*_m.cc genericNode/contentExchange/static/message/*_m.h
	-rm -f genericNode/contentExchange/static/state/*_m.cc genericNode/contentExchange/static/state/*_m.h
	-rm -f message/*_m.cc message/*_m.h
	-rm -f models/*_m.cc models/*_m.h
	-rm -f models/RNP/*_m.cc models/RNP/*_m.h
	-rm -f models/RNP/caches/*_m.cc models/RNP/caches/*_m.h
	-rm -f models/RNP/dataset/*_m.cc models/RNP/dataset/*_m.h
	-rm -f models/RNP/results/*_m.cc models/RNP/results/*_m.h
	-rm -f models/RNP/stats/*_m.cc models/RNP/stats/*_m.h
	-rm -f models/RNP_LAYOUT_1/*_m.cc models/RNP_LAYOUT_1/*_m.h
	-rm -f models/RNP_LAYOUT_2/*_m.cc models/RNP_LAYOUT_2/*_m.h
	-rm -f models/_batch/*_m.cc models/_batch/*_m.h
	-rm -f models/_stats/*_m.cc models/_stats/*_m.h
	-rm -f models/exp01/*_m.cc models/exp01/*_m.h
	-rm -f models/exp01/caches/*_m.cc models/exp01/caches/*_m.h
	-rm -f models/exp01/dataset/*_m.cc models/exp01/dataset/*_m.h
	-rm -f models/exp01/results/*_m.cc models/exp01/results/*_m.h
	-rm -f models/exp01/stats/*_m.cc models/exp01/stats/*_m.h
	-rm -f models/exp02/*_m.cc models/exp02/*_m.h
	-rm -f models/exp02/caches/*_m.cc models/exp02/caches/*_m.h
	-rm -f models/exp02/dataset/*_m.cc models/exp02/dataset/*_m.h
	-rm -f models/exp02/stats/*_m.cc models/exp02/stats/*_m.h
	-rm -f models/exp11/*_m.cc models/exp11/*_m.h
	-rm -f models/exp11/caches/*_m.cc models/exp11/caches/*_m.h
	-rm -f models/exp11/dataset/*_m.cc models/exp11/dataset/*_m.h
	-rm -f models/exp11/results/*_m.cc models/exp11/results/*_m.h
	-rm -f models/exp11/stats/*_m.cc models/exp11/stats/*_m.h
	-rm -f models/exp12/*_m.cc models/exp12/*_m.h
	-rm -f models/exp12/caches/*_m.cc models/exp12/caches/*_m.h
	-rm -f models/exp12/dataset/*_m.cc models/exp12/dataset/*_m.h
	-rm -f models/exp12/results/*_m.cc models/exp12/results/*_m.h
	-rm -f models/exp12/stats/*_m.cc models/exp12/stats/*_m.h
	-rm -f models/nHost/*_m.cc models/nHost/*_m.h
	-rm -f models/nHost/caches/*_m.cc models/nHost/caches/*_m.h
	-rm -f models/nHost/dataset/*_m.cc models/nHost/dataset/*_m.h
	-rm -f models/nHost/results/*_m.cc models/nHost/results/*_m.h
	-rm -f models/nHost/stats/*_m.cc models/nHost/stats/*_m.h
	-rm -f models/simpleCDN/*_m.cc models/simpleCDN/*_m.h
	-rm -f models/simpleCDN/caches/*_m.cc models/simpleCDN/caches/*_m.h
	-rm -f models/simpleCDN/dataset/*_m.cc models/simpleCDN/dataset/*_m.h
	-rm -f models/simpleCDN/results/*_m.cc models/simpleCDN/results/*_m.h
	-rm -f models/simpleCDN/stats/*_m.cc models/simpleCDN/stats/*_m.h
	-rm -f models/teste/*_m.cc models/teste/*_m.h
	-rm -f models/teste/caches/*_m.cc models/teste/caches/*_m.h
	-rm -f models/teste/dataset/*_m.cc models/teste/dataset/*_m.h
	-rm -f models/teste/results/*_m.cc models/teste/results/*_m.h
	-rm -f models/teste/stats/*_m.cc models/teste/stats/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc cache/*.cc coordinate/*.cc coordinate/command/*.cc coordinate/stats/*.cc execption/*.cc genericNode/*.cc genericNode/contentExchange/*.cc genericNode/contentExchange/static/*.cc genericNode/contentExchange/static/command/*.cc genericNode/contentExchange/static/handler/*.cc genericNode/contentExchange/static/message/*.cc genericNode/contentExchange/static/state/*.cc message/*.cc models/*.cc models/RNP/*.cc models/RNP/caches/*.cc models/RNP/dataset/*.cc models/RNP/results/*.cc models/RNP/stats/*.cc models/RNP_LAYOUT_1/*.cc models/RNP_LAYOUT_2/*.cc models/_batch/*.cc models/_stats/*.cc models/exp01/*.cc models/exp01/caches/*.cc models/exp01/dataset/*.cc models/exp01/results/*.cc models/exp01/stats/*.cc models/exp02/*.cc models/exp02/caches/*.cc models/exp02/dataset/*.cc models/exp02/stats/*.cc models/exp11/*.cc models/exp11/caches/*.cc models/exp11/dataset/*.cc models/exp11/results/*.cc models/exp11/stats/*.cc models/exp12/*.cc models/exp12/caches/*.cc models/exp12/dataset/*.cc models/exp12/results/*.cc models/exp12/stats/*.cc models/nHost/*.cc models/nHost/caches/*.cc models/nHost/dataset/*.cc models/nHost/results/*.cc models/nHost/stats/*.cc models/simpleCDN/*.cc models/simpleCDN/caches/*.cc models/simpleCDN/dataset/*.cc models/simpleCDN/results/*.cc models/simpleCDN/stats/*.cc models/teste/*.cc models/teste/caches/*.cc models/teste/dataset/*.cc models/teste/results/*.cc models/teste/stats/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/cache/LfuCache.o: cache/LfuCache.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	cache/Cache.h \
	cache/AnakreonCommon.h \
	cache/InformationSet.h \
	cache/LfuCache.h \
	execption/Exceptions.h
$O/cache/InformationSet.o: cache/InformationSet.cc \
	cache/InformationSet.h
$O/cache/MruCache.o: cache/MruCache.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	cache/MruCache.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	cache/Cache.h \
	cache/AnakreonCommon.h \
	cache/InformationSet.h \
	execption/Exceptions.h
$O/cache/LruCache.o: cache/LruCache.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	cache/Cache.h \
	cache/AnakreonCommon.h \
	cache/InformationSet.h \
	execption/Exceptions.h \
	cache/LruCache.h
$O/cache/Cache.o: cache/Cache.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	cache/Cache.h \
	cache/InformationSet.h
$O/coordinate/CDN_CentralUnit_Reply.o: coordinate/CDN_CentralUnit_Reply.cc \
	coordinate/CDN_CentralUnit_Reply.h \
	genericNode/contentExchange/static/message/ServableItem.h
$O/coordinate/CDN_RequestsAssignerReceiver.o: coordinate/CDN_RequestsAssignerReceiver.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	message/RequestMessage.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/stats/Stats.h \
	message/InterNodeRequestProtocol.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ClientUnit.h \
	coordinate/command/Commands.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/ServicePeer.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/coordinate/CDN_CentralUnit.o: coordinate/CDN_CentralUnit.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	message/RequestMessage.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	coordinate/CDN_CentralUnit_Reply.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/stats/Stats.h \
	message/InterNodeRequestProtocol.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ClientUnit.h \
	coordinate/command/Commands.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/ServicePeer.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/coordinate/CentralUnit.o: coordinate/CentralUnit.cc \
	coordinate/CentralUnit.h
$O/coordinate/command/Commands.o: coordinate/command/Commands.cc \
	coordinate/command/Commands.h
$O/coordinate/command/CDN_Commands.o: coordinate/command/CDN_Commands.cc \
	coordinate/command/Commands.h \
	genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	cache/AnakreonCommon.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	message/Request.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/coordinate/stats/CacheLogEntry.o: coordinate/stats/CacheLogEntry.cc \
	coordinate/stats/CacheLogEntry.h \
	coordinate/stats/LogEntry.h
$O/coordinate/stats/Stats.o: coordinate/stats/Stats.cc \
	coordinate/stats/CacheLogEntry.h \
	coordinate/stats/LogEntry.h \
	coordinate/stats/Stats.h \
	coordinate/stats/RequestLogEntry.h
$O/coordinate/stats/statistic.o: coordinate/stats/statistic.cc \
	coordinate/stats/statistic.h
$O/coordinate/stats/RequestLogEntry.o: coordinate/stats/RequestLogEntry.cc \
	coordinate/stats/LogEntry.h \
	coordinate/stats/RequestLogEntry.h
$O/genericNode/PortNumberAllocator.o: genericNode/PortNumberAllocator.cc \
	execption/Exceptions.h
$O/genericNode/contentExchange/Negotiator.o: genericNode/contentExchange/Negotiator.cc \
	genericNode/contentExchange/Negotiator.h
$O/genericNode/contentExchange/ServerUnit.o: genericNode/contentExchange/ServerUnit.cc \
	genericNode/contentExchange/ServerUnit.h
$O/genericNode/contentExchange/StateTester.o: genericNode/contentExchange/StateTester.cc \
	genericNode/contentExchange/StateTester.h
$O/genericNode/contentExchange/ClientUnit.o: genericNode/contentExchange/ClientUnit.cc \
	genericNode/contentExchange/ClientUnit.h
$O/genericNode/contentExchange/ServicePeer.o: genericNode/contentExchange/ServicePeer.cc \
	genericNode/contentExchange/ServicePeer.h
$O/genericNode/contentExchange/RequestsAssignerReceiver.o: genericNode/contentExchange/RequestsAssignerReceiver.cc \
	genericNode/contentExchange/RequestsAssignerReceiver.h
$O/genericNode/contentExchange/AlternateServerDetector.o: genericNode/contentExchange/AlternateServerDetector.cc \
	genericNode/contentExchange/AlternateServerDetector.h
$O/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o: genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	message/RequestMessage.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	coordinate/CDN_CentralUnit_Reply.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	message/InterNodeRequestProtocol.h \
	coordinate/stats/Stats.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ClientUnit.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/ServicePeer.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/genericNode/contentExchange/static/StaticContentExchange_StateTester.o: genericNode/contentExchange/static/StaticContentExchange_StateTester.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	message/RequestMessage.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/Stats.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	genericNode/contentExchange/ClientUnit.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	cache/Cache.h \
	genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o: genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	message/RequestMessage.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/stats/Stats.h \
	message/InterNodeRequestProtocol.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/command/Commands.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	genericNode/contentExchange/ClientUnit.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o: genericNode/contentExchange/static/StaticContentExchange_ServerUnit.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	cache/InformationSet.h \
	message/RequestMessage.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	message/InterNodeRequestProtocol.h \
	coordinate/stats/Stats.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/ClientUnit.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/ServicePeer.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o: genericNode/contentExchange/static/StaticContentExchange_ServicePeer.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	cache/InformationSet.h \
	message/RequestMessage.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	cache/LfuCache.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/stats/Stats.h \
	message/InterNodeRequestProtocol.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/command/Commands.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	genericNode/contentExchange/ClientUnit.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	cache/MruCache.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	cache/LruCache.h
$O/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o: genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	message/RequestMessage.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/CacheLogEntry.h \
	message/InterNodeRequestProtocol.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/stats/Stats.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/ClientUnit.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/ServicePeer.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o: genericNode/contentExchange/static/StaticContentExchange_ClientUnit.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	message/RequestMessage.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	coordinate/CDN_CentralUnit_Reply.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/Stats.h \
	message/InterNodeRequestProtocol.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CentralUnit.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/ClientUnit.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	cache/Cache.h \
	genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/genericNode/contentExchange/static/command/Command.o: genericNode/contentExchange/static/command/Command.cc \
	genericNode/contentExchange/static/command/Command.h
$O/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o: genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.cc \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	message/Request.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o: genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	cache/InformationSet.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/static/handler/DownloadersBase.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/stats/Stats.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	genericNode/contentExchange/ClientUnit.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	genericNode/contentExchange/ServerUnit.h \
	coordinate/command/CDN_Commands.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	cache/Cache.h \
	genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	genericNode/contentExchange/static/state/State.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h
$O/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o: genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.cc \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	cache/InformationSet.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/Stats.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/ClientUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/CDN_CentralUnit.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	cache/Cache.h \
	genericNode/contentExchange/static/handler/Handler.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	message/RequestMessage.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	message/InterNodeRequestProtocol.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/ServerUnit.h \
	genericNode/contentExchange/static/message/StaticObjectMessage.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h
$O/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o: genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.cc \
	genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.h \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	cache/InformationSet.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/Stats.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	cache/Cache.h \
	genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	cache/LruCache.h \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	message/RequestMessage.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/static/handler/DownloadersBase.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	message/InterNodeRequestProtocol.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	genericNode/contentExchange/static/message/StaticObjectMessage.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h
$O/genericNode/contentExchange/static/handler/DownloadersBase.o: genericNode/contentExchange/static/handler/DownloadersBase.cc \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	cache/InformationSet.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/Stats.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/ClientUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	coordinate/CDN_CentralUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	cache/Cache.h \
	genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	message/RequestMessage.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/static/handler/DownloadersBase.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/ServerUnit.h \
	genericNode/contentExchange/static/message/StaticObjectMessage.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h
$O/genericNode/contentExchange/static/handler/Handler.o: genericNode/contentExchange/static/handler/Handler.cc \
	message/Request.h \
	coordinate/stats/LogEntry.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/static/handler/Handler.h \
	coordinate/stats/RequestLogEntry.h
$O/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o: genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.cc \
	message/RequestMessage_Base_m.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	genericNode/contentExchange/Negotiator.h \
	cache/InformationSet.h \
	coordinate/CDN_RequestsAssignerReceiver.h \
	coordinate/stats/CacheLogEntry.h \
	genericNode/contentExchange/StateTester.h \
	coordinate/stats/Stats.h \
	coordinate/CentralUnit.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	coordinate/CDN_CentralUnit.h \
	genericNode/contentExchange/AlternateServerDetector.h \
	genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	cache/Cache.h \
	genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	cache/LruCache.h \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	message/RequestMessage.h \
	genericNode/contentExchange/RequestsAssignerReceiver.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	message/Request.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	genericNode/contentExchange/static/handler/DownloadersBase.h \
	message/InterNodeRequestProtocol.h \
	genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	coordinate/command/Commands.h \
	genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	genericNode/contentExchange/ServerUnit.h \
	genericNode/contentExchange/static/message/StaticObjectMessage.h \
	coordinate/command/CDN_Commands.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	genericNode/contentExchange/ServicePeer.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.h \
	genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	genericNode/contentExchange/static/state/State.h
$O/genericNode/contentExchange/static/message/StaticObjectMessage.o: genericNode/contentExchange/static/message/StaticObjectMessage.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	message/Request.h \
	coordinate/stats/LogEntry.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	coordinate/stats/RequestLogEntry.h \
	genericNode/contentExchange/static/message/StaticObjectMessage.h
$O/genericNode/contentExchange/static/message/StaticObject.o: genericNode/contentExchange/static/message/StaticObject.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	genericNode/contentExchange/static/message/ServableItem.h
$O/genericNode/contentExchange/static/message/ServableItem.o: genericNode/contentExchange/static/message/ServableItem.cc \
	genericNode/contentExchange/static/message/ServableItem.h
$O/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o: genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.cc \
	genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h
$O/genericNode/contentExchange/static/state/State.o: genericNode/contentExchange/static/state/State.cc \
	cache/InformationSet.h \
	genericNode/contentExchange/static/state/State.h
$O/genericNode/contentExchange/static/state/StaticContentExchange_State.o: genericNode/contentExchange/static/state/StaticContentExchange_State.cc \
	genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	cache/InformationSet.h \
	execption/Exceptions.h \
	genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	message/Request.h \
	coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	genericNode/contentExchange/static/handler/Handler.h \
	cache/Cache.h \
	coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	genericNode/contentExchange/static/state/State.h
$O/message/RequestMessage_Base_m.o: message/RequestMessage_Base_m.cc \
	message/RequestMessage_Base_m.h
$O/message/Request.o: message/Request.cc \
	message/Request.h \
	coordinate/stats/LogEntry.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	coordinate/stats/RequestLogEntry.h
$O/message/InterNodeRequestProtocol.o: message/InterNodeRequestProtocol.cc \
	message/Request.h \
	message/RequestMessage_Base_m.h \
	coordinate/stats/LogEntry.h \
	message/InterNodeRequestProtocol.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	coordinate/stats/RequestLogEntry.h \
	message/RequestMessage.h
$O/message/RequestMessage.o: message/RequestMessage.cc \
	message/Request.h \
	message/RequestMessage_Base_m.h \
	coordinate/stats/LogEntry.h \
	genericNode/contentExchange/static/command/Command.h \
	genericNode/contentExchange/static/message/ServableItem.h \
	coordinate/stats/RequestLogEntry.h \
	message/RequestMessage.h

