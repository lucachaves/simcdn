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
    -Imodels \
    -Imodels/exp01 \
    -Imodels/exp01/caches \
    -Imodels/exp01/dataset \
    -Imodels/exp01/results \
    -Imodels/exp01/stats \
    -Imodels/exp02 \
    -Imodels/exp02/caches \
    -Imodels/exp02/dataset \
    -Imodels/exp02/exp02 \
    -Imodels/exp02/exp02/caches \
    -Imodels/exp02/exp02/dataset \
    -Imodels/exp02/exp02/stats \
    -Imodels/exp02/stats \
    -Isrc \
    -Isrc/generator \
    -Isrc/generator/RNP \
    -Isrc/generator/RNP/bootle \
    -Isrc/generator/RNP/bootle/exp02 \
    -Isrc/generator/RNP/bootle/exp02/caches \
    -Isrc/generator/RNP/bootle/exp02/dataset \
    -Isrc/generator/RNP/bootle/exp02/stats \
    -Isrc/generator/estados \
    -Isrc/simulator \
    -Isrc/simulator/cache \
    -Isrc/simulator/coordinate \
    -Isrc/simulator/coordinate/command \
    -Isrc/simulator/coordinate/stats \
    -Isrc/simulator/execption \
    -Isrc/simulator/genericNode \
    -Isrc/simulator/genericNode/contentExchange \
    -Isrc/simulator/genericNode/contentExchange/static \
    -Isrc/simulator/genericNode/contentExchange/static/command \
    -Isrc/simulator/genericNode/contentExchange/static/handler \
    -Isrc/simulator/genericNode/contentExchange/static/message \
    -Isrc/simulator/genericNode/contentExchange/static/state \
    -Isrc/simulator/message

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
    $O/src/simulator/cache/Cache.o \
    $O/src/simulator/cache/LfuCache.o \
    $O/src/simulator/cache/MruCache.o \
    $O/src/simulator/cache/LruCache.o \
    $O/src/simulator/cache/InformationSet.o \
    $O/src/simulator/coordinate/CDN_RequestsAssignerReceiver.o \
    $O/src/simulator/coordinate/CDN_CentralUnit.o \
    $O/src/simulator/coordinate/CentralUnit.o \
    $O/src/simulator/coordinate/CDN_CentralUnit_Reply.o \
    $O/src/simulator/coordinate/command/Commands.o \
    $O/src/simulator/coordinate/command/CDN_Commands.o \
    $O/src/simulator/coordinate/stats/statistic.o \
    $O/src/simulator/coordinate/stats/CacheLogEntry.o \
    $O/src/simulator/coordinate/stats/RequestLogEntry.o \
    $O/src/simulator/coordinate/stats/Stats.o \
    $O/src/simulator/genericNode/PortNumberAllocator.o \
    $O/src/simulator/genericNode/contentExchange/Negotiator.o \
    $O/src/simulator/genericNode/contentExchange/AlternateServerDetector.o \
    $O/src/simulator/genericNode/contentExchange/ServerUnit.o \
    $O/src/simulator/genericNode/contentExchange/ServicePeer.o \
    $O/src/simulator/genericNode/contentExchange/ClientUnit.o \
    $O/src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.o \
    $O/src/simulator/genericNode/contentExchange/StateTester.o \
    $O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o \
    $O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o \
    $O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o \
    $O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o \
    $O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o \
    $O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o \
    $O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.o \
    $O/src/simulator/genericNode/contentExchange/static/command/Command.o \
    $O/src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o \
    $O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o \
    $O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o \
    $O/src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.o \
    $O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o \
    $O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o \
    $O/src/simulator/genericNode/contentExchange/static/handler/Handler.o \
    $O/src/simulator/genericNode/contentExchange/static/message/StaticObject.o \
    $O/src/simulator/genericNode/contentExchange/static/message/ServableItem.o \
    $O/src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.o \
    $O/src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.o \
    $O/src/simulator/genericNode/contentExchange/static/state/State.o \
    $O/src/simulator/message/RequestMessage.o \
    $O/src/simulator/message/Request.o \
    $O/src/simulator/message/InterNodeRequestProtocol.o \
    $O/src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o \
    $O/src/simulator/message/RequestMessage_Base_m.o

# Message files
MSGFILES = \
    src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base.msg \
    src/simulator/message/RequestMessage_Base.msg

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
	-rm -f models/*_m.cc models/*_m.h
	-rm -f models/exp01/*_m.cc models/exp01/*_m.h
	-rm -f models/exp01/caches/*_m.cc models/exp01/caches/*_m.h
	-rm -f models/exp01/dataset/*_m.cc models/exp01/dataset/*_m.h
	-rm -f models/exp01/results/*_m.cc models/exp01/results/*_m.h
	-rm -f models/exp01/stats/*_m.cc models/exp01/stats/*_m.h
	-rm -f models/exp02/*_m.cc models/exp02/*_m.h
	-rm -f models/exp02/caches/*_m.cc models/exp02/caches/*_m.h
	-rm -f models/exp02/dataset/*_m.cc models/exp02/dataset/*_m.h
	-rm -f models/exp02/exp02/*_m.cc models/exp02/exp02/*_m.h
	-rm -f models/exp02/exp02/caches/*_m.cc models/exp02/exp02/caches/*_m.h
	-rm -f models/exp02/exp02/dataset/*_m.cc models/exp02/exp02/dataset/*_m.h
	-rm -f models/exp02/exp02/stats/*_m.cc models/exp02/exp02/stats/*_m.h
	-rm -f models/exp02/stats/*_m.cc models/exp02/stats/*_m.h
	-rm -f src/*_m.cc src/*_m.h
	-rm -f src/generator/*_m.cc src/generator/*_m.h
	-rm -f src/generator/RNP/*_m.cc src/generator/RNP/*_m.h
	-rm -f src/generator/RNP/bootle/*_m.cc src/generator/RNP/bootle/*_m.h
	-rm -f src/generator/RNP/bootle/exp02/*_m.cc src/generator/RNP/bootle/exp02/*_m.h
	-rm -f src/generator/RNP/bootle/exp02/caches/*_m.cc src/generator/RNP/bootle/exp02/caches/*_m.h
	-rm -f src/generator/RNP/bootle/exp02/dataset/*_m.cc src/generator/RNP/bootle/exp02/dataset/*_m.h
	-rm -f src/generator/RNP/bootle/exp02/stats/*_m.cc src/generator/RNP/bootle/exp02/stats/*_m.h
	-rm -f src/generator/estados/*_m.cc src/generator/estados/*_m.h
	-rm -f src/simulator/*_m.cc src/simulator/*_m.h
	-rm -f src/simulator/cache/*_m.cc src/simulator/cache/*_m.h
	-rm -f src/simulator/coordinate/*_m.cc src/simulator/coordinate/*_m.h
	-rm -f src/simulator/coordinate/command/*_m.cc src/simulator/coordinate/command/*_m.h
	-rm -f src/simulator/coordinate/stats/*_m.cc src/simulator/coordinate/stats/*_m.h
	-rm -f src/simulator/execption/*_m.cc src/simulator/execption/*_m.h
	-rm -f src/simulator/genericNode/*_m.cc src/simulator/genericNode/*_m.h
	-rm -f src/simulator/genericNode/contentExchange/*_m.cc src/simulator/genericNode/contentExchange/*_m.h
	-rm -f src/simulator/genericNode/contentExchange/static/*_m.cc src/simulator/genericNode/contentExchange/static/*_m.h
	-rm -f src/simulator/genericNode/contentExchange/static/command/*_m.cc src/simulator/genericNode/contentExchange/static/command/*_m.h
	-rm -f src/simulator/genericNode/contentExchange/static/handler/*_m.cc src/simulator/genericNode/contentExchange/static/handler/*_m.h
	-rm -f src/simulator/genericNode/contentExchange/static/message/*_m.cc src/simulator/genericNode/contentExchange/static/message/*_m.h
	-rm -f src/simulator/genericNode/contentExchange/static/state/*_m.cc src/simulator/genericNode/contentExchange/static/state/*_m.h
	-rm -f src/simulator/message/*_m.cc src/simulator/message/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc models/*.cc models/exp01/*.cc models/exp01/caches/*.cc models/exp01/dataset/*.cc models/exp01/results/*.cc models/exp01/stats/*.cc models/exp02/*.cc models/exp02/caches/*.cc models/exp02/dataset/*.cc models/exp02/exp02/*.cc models/exp02/exp02/caches/*.cc models/exp02/exp02/dataset/*.cc models/exp02/exp02/stats/*.cc models/exp02/stats/*.cc src/*.cc src/generator/*.cc src/generator/RNP/*.cc src/generator/RNP/bootle/*.cc src/generator/RNP/bootle/exp02/*.cc src/generator/RNP/bootle/exp02/caches/*.cc src/generator/RNP/bootle/exp02/dataset/*.cc src/generator/RNP/bootle/exp02/stats/*.cc src/generator/estados/*.cc src/simulator/*.cc src/simulator/cache/*.cc src/simulator/coordinate/*.cc src/simulator/coordinate/command/*.cc src/simulator/coordinate/stats/*.cc src/simulator/execption/*.cc src/simulator/genericNode/*.cc src/simulator/genericNode/contentExchange/*.cc src/simulator/genericNode/contentExchange/static/*.cc src/simulator/genericNode/contentExchange/static/command/*.cc src/simulator/genericNode/contentExchange/static/handler/*.cc src/simulator/genericNode/contentExchange/static/message/*.cc src/simulator/genericNode/contentExchange/static/state/*.cc src/simulator/message/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/simulator/cache/LruCache.o: src/simulator/cache/LruCache.cc \
	src/simulator/cache/Cache.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/cache/LruCache.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/cache/AnakreonCommon.h
$O/src/simulator/cache/MruCache.o: src/simulator/cache/MruCache.cc \
	src/simulator/cache/Cache.h \
	src/simulator/cache/MruCache.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/cache/AnakreonCommon.h
$O/src/simulator/cache/Cache.o: src/simulator/cache/Cache.cc \
	src/simulator/cache/Cache.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h
$O/src/simulator/cache/LfuCache.o: src/simulator/cache/LfuCache.cc \
	src/simulator/cache/Cache.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/cache/LfuCache.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/cache/AnakreonCommon.h
$O/src/simulator/cache/InformationSet.o: src/simulator/cache/InformationSet.cc \
	src/simulator/cache/InformationSet.h
$O/src/simulator/coordinate/CDN_CentralUnit.o: src/simulator/coordinate/CDN_CentralUnit.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	src/simulator/coordinate/stats/Stats.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/message/Request.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/cache/InformationSet.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/coordinate/CDN_CentralUnit_Reply.h \
	src/simulator/execption/Exceptions.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/coordinate/CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/coordinate/CDN_CentralUnit_Reply.o: src/simulator/coordinate/CDN_CentralUnit_Reply.cc \
	src/simulator/coordinate/CDN_CentralUnit_Reply.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h
$O/src/simulator/coordinate/CentralUnit.o: src/simulator/coordinate/CentralUnit.cc \
	src/simulator/coordinate/CentralUnit.h
$O/src/simulator/coordinate/CDN_RequestsAssignerReceiver.o: src/simulator/coordinate/CDN_RequestsAssignerReceiver.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/message/Request.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/cache/InformationSet.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/execption/Exceptions.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/coordinate/CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/coordinate/command/Commands.o: src/simulator/coordinate/command/Commands.cc \
	src/simulator/coordinate/command/Commands.h
$O/src/simulator/coordinate/command/CDN_Commands.o: src/simulator/coordinate/command/CDN_Commands.cc \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/cache/AnakreonCommon.h
$O/src/simulator/coordinate/stats/statistic.o: src/simulator/coordinate/stats/statistic.cc \
	src/simulator/coordinate/stats/statistic.h
$O/src/simulator/coordinate/stats/Stats.o: src/simulator/coordinate/stats/Stats.cc \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	src/simulator/coordinate/stats/Stats.h
$O/src/simulator/coordinate/stats/RequestLogEntry.o: src/simulator/coordinate/stats/RequestLogEntry.cc \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h
$O/src/simulator/coordinate/stats/CacheLogEntry.o: src/simulator/coordinate/stats/CacheLogEntry.cc \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/coordinate/stats/LogEntry.h
$O/src/simulator/genericNode/PortNumberAllocator.o: src/simulator/genericNode/PortNumberAllocator.cc \
	src/simulator/execption/Exceptions.h
$O/src/simulator/genericNode/contentExchange/ClientUnit.o: src/simulator/genericNode/contentExchange/ClientUnit.cc \
	src/simulator/genericNode/contentExchange/ClientUnit.h
$O/src/simulator/genericNode/contentExchange/ServerUnit.o: src/simulator/genericNode/contentExchange/ServerUnit.cc \
	src/simulator/genericNode/contentExchange/ServerUnit.h
$O/src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.o: src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.cc \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h
$O/src/simulator/genericNode/contentExchange/Negotiator.o: src/simulator/genericNode/contentExchange/Negotiator.cc \
	src/simulator/genericNode/contentExchange/Negotiator.h
$O/src/simulator/genericNode/contentExchange/ServicePeer.o: src/simulator/genericNode/contentExchange/ServicePeer.cc \
	src/simulator/genericNode/contentExchange/ServicePeer.h
$O/src/simulator/genericNode/contentExchange/AlternateServerDetector.o: src/simulator/genericNode/contentExchange/AlternateServerDetector.cc \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h
$O/src/simulator/genericNode/contentExchange/StateTester.o: src/simulator/genericNode/contentExchange/StateTester.cc \
	src/simulator/genericNode/contentExchange/StateTester.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/cache/InformationSet.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/execption/Exceptions.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/message/Request.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/coordinate/CDN_CentralUnit_Reply.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/cache/InformationSet.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/coordinate/CDN_CentralUnit_Reply.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/coordinate/CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.cc \
	src/simulator/cache/Cache.h \
	src/simulator/cache/MruCache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	src/simulator/coordinate/stats/Stats.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/cache/LfuCache.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/cache/InformationSet.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/cache/LruCache.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	src/simulator/coordinate/stats/Stats.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/execption/Exceptions.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/coordinate/CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/simulator/coordinate/CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o: src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.cc \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h
$O/src/simulator/genericNode/contentExchange/static/command/Command.o: src/simulator/genericNode/contentExchange/static/command/Command.cc \
	src/simulator/genericNode/contentExchange/static/command/Command.h
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/cache/InformationSet.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/handler/Handler.o: src/simulator/genericNode/contentExchange/static/handler/Handler.cc \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.cc \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/message/Request.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.h \
	src/simulator/coordinate/CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/state/State.h \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.cc \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/message/Request.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/cache/LruCache.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/execption/Exceptions.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/simulator/genericNode/contentExchange/static/state/State.h \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h
$O/src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.o: src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.cc \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/message/Request.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/simulator/genericNode/contentExchange/static/state/State.h \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.cc \
	src/simulator/genericNode/contentExchange/ClientUnit.h \
	src/simulator/genericNode/contentExchange/AlternateServerDetector.h \
	src/simulator/coordinate/stats/Stats.h \
	src/simulator/message/Request.h \
	src/simulator/coordinate/CDN_RequestsAssignerReceiver.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/ServerUnit.h \
	src/simulator/coordinate/stats/CacheLogEntry.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/simulator/cache/LruCache.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/simulator/genericNode/contentExchange/Negotiator.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/simulator/coordinate/CentralUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/simulator/genericNode/contentExchange/static/state/State.h \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/simulator/coordinate/CDN_CentralUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/simulator/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/coordinate/command/CDN_Commands.h \
	src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.h \
	src/simulator/coordinate/command/Commands.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h
$O/src/simulator/genericNode/contentExchange/static/message/StaticObject.o: src/simulator/genericNode/contentExchange/static/message/StaticObject.cc \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h
$O/src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.o: src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.cc \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h
$O/src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o: src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.cc \
	src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h
$O/src/simulator/genericNode/contentExchange/static/message/ServableItem.o: src/simulator/genericNode/contentExchange/static/message/ServableItem.cc \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h
$O/src/simulator/genericNode/contentExchange/static/state/State.o: src/simulator/genericNode/contentExchange/static/state/State.cc \
	src/simulator/cache/InformationSet.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.o: src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.cc \
	src/simulator/cache/Cache.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/simulator/genericNode/contentExchange/static/message/StaticObject.h \
	src/simulator/genericNode/contentExchange/static/handler/Handler.h \
	src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/simulator/execption/Exceptions.h \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/simulator/cache/InformationSet.h \
	src/simulator/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h \
	src/simulator/genericNode/contentExchange/static/state/State.h
$O/src/simulator/message/RequestMessage_Base_m.o: src/simulator/message/RequestMessage_Base_m.cc \
	src/simulator/message/RequestMessage_Base_m.h
$O/src/simulator/message/RequestMessage.o: src/simulator/message/RequestMessage.cc \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h
$O/src/simulator/message/Request.o: src/simulator/message/Request.cc \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h
$O/src/simulator/message/InterNodeRequestProtocol.o: src/simulator/message/InterNodeRequestProtocol.cc \
	src/simulator/message/Request.h \
	src/simulator/genericNode/contentExchange/static/message/ServableItem.h \
	src/simulator/message/InterNodeRequestProtocol.h \
	src/simulator/coordinate/stats/LogEntry.h \
	src/simulator/message/RequestMessage.h \
	src/simulator/message/RequestMessage_Base_m.h \
	src/simulator/coordinate/stats/RequestLogEntry.h \
	src/simulator/genericNode/contentExchange/static/command/Command.h

