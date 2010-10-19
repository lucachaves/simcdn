#
# OMNeT++/OMNEST Makefile for CDNRef
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I../inet/src/networklayer/ipv4 -I../inet/src/networklayer/common -I../inet/src/networklayer/rsvp_te -I../inet/src/networklayer/icmpv6 -I../inet/src/transport/tcp -I../inet/src/networklayer/mpls -I../inet/src/base -I../inet/src/networklayer/ted -I../inet/src/util/headerserializers -I../inet/src/networklayer/contract -I../inet/src/util -I../inet/src/transport/contract -I../inet/src/linklayer/mfcore -I../inet/src/networklayer/ipv6 -I../inet/src/transport/sctp -I../inet/src/world -I../inet/src/applications/pingapp -I../inet/src/linklayer/contract -I../inet/src/networklayer/arp -I../inet/src/networklayer/ldp -I../inet/src/transport/udp -L../inet/out/$(CONFIGNAME)/src -linet -KINET_PROJ=../inet
#

# Name of target to be created (-o option)
TARGET = CDNRef$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../inet/src/networklayer/ipv4 \
    -I../inet/src/networklayer/common \
    -I../inet/src/networklayer/rsvp_te \
    -I../inet/src/networklayer/icmpv6 \
    -I../inet/src/transport/tcp \
    -I../inet/src/networklayer/mpls \
    -I../inet/src/base \
    -I../inet/src/networklayer/ted \
    -I../inet/src/util/headerserializers \
    -I../inet/src/networklayer/contract \
    -I../inet/src/util \
    -I../inet/src/transport/contract \
    -I../inet/src/linklayer/mfcore \
    -I../inet/src/networklayer/ipv6 \
    -I../inet/src/transport/sctp \
    -I../inet/src/world \
    -I../inet/src/applications/pingapp \
    -I../inet/src/linklayer/contract \
    -I../inet/src/networklayer/arp \
    -I../inet/src/networklayer/ldp \
    -I../inet/src/transport/udp \
    -I. \
    -Imodels \
    -Imodels/RNP \
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
    -Imodels/exp11 \
    -Imodels/exp12 \
    -Imodels/nHost \
    -Imodels/simpleCDN \
    -Imodels/teste \
    -Isrc \
    -Isrc/cache \
    -Isrc/coordinate \
    -Isrc/coordinate/command \
    -Isrc/coordinate/stats \
    -Isrc/execption \
    -Isrc/generator \
    -Isrc/generator/RNP \
    -Isrc/generator/RNP/bootle \
    -Isrc/generator/estados \
    -Isrc/genericNode \
    -Isrc/genericNode/contentExchange \
    -Isrc/genericNode/contentExchange/static \
    -Isrc/genericNode/contentExchange/static/command \
    -Isrc/genericNode/contentExchange/static/handler \
    -Isrc/genericNode/contentExchange/static/message \
    -Isrc/genericNode/contentExchange/static/state \
    -Isrc/message \
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
	-rm -f models/RNP/*_m.cc models/RNP/*_m.h
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
	-rm -f models/exp11/*_m.cc models/exp11/*_m.h
	-rm -f models/exp12/*_m.cc models/exp12/*_m.h
	-rm -f models/nHost/*_m.cc models/nHost/*_m.h
	-rm -f models/simpleCDN/*_m.cc models/simpleCDN/*_m.h
	-rm -f models/teste/*_m.cc models/teste/*_m.h
	-rm -f src/*_m.cc src/*_m.h
	-rm -f src/cache/*_m.cc src/cache/*_m.h
	-rm -f src/coordinate/*_m.cc src/coordinate/*_m.h
	-rm -f src/coordinate/command/*_m.cc src/coordinate/command/*_m.h
	-rm -f src/coordinate/stats/*_m.cc src/coordinate/stats/*_m.h
	-rm -f src/execption/*_m.cc src/execption/*_m.h
	-rm -f src/generator/*_m.cc src/generator/*_m.h
	-rm -f src/generator/RNP/*_m.cc src/generator/RNP/*_m.h
	-rm -f src/generator/RNP/bootle/*_m.cc src/generator/RNP/bootle/*_m.h
	-rm -f src/generator/estados/*_m.cc src/generator/estados/*_m.h
	-rm -f src/genericNode/*_m.cc src/genericNode/*_m.h
	-rm -f src/genericNode/contentExchange/*_m.cc src/genericNode/contentExchange/*_m.h
	-rm -f src/genericNode/contentExchange/static/*_m.cc src/genericNode/contentExchange/static/*_m.h
	-rm -f src/genericNode/contentExchange/static/command/*_m.cc src/genericNode/contentExchange/static/command/*_m.h
	-rm -f src/genericNode/contentExchange/static/handler/*_m.cc src/genericNode/contentExchange/static/handler/*_m.h
	-rm -f src/genericNode/contentExchange/static/message/*_m.cc src/genericNode/contentExchange/static/message/*_m.h
	-rm -f src/genericNode/contentExchange/static/state/*_m.cc src/genericNode/contentExchange/static/state/*_m.h
	-rm -f src/message/*_m.cc src/message/*_m.h
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
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc models/*.cc models/RNP/*.cc models/RNP_LAYOUT_1/*.cc models/RNP_LAYOUT_2/*.cc models/_batch/*.cc models/_stats/*.cc models/exp01/*.cc models/exp01/caches/*.cc models/exp01/dataset/*.cc models/exp01/results/*.cc models/exp01/stats/*.cc models/exp02/*.cc models/exp11/*.cc models/exp12/*.cc models/nHost/*.cc models/simpleCDN/*.cc models/teste/*.cc src/*.cc src/cache/*.cc src/coordinate/*.cc src/coordinate/command/*.cc src/coordinate/stats/*.cc src/execption/*.cc src/generator/*.cc src/generator/RNP/*.cc src/generator/RNP/bootle/*.cc src/generator/estados/*.cc src/genericNode/*.cc src/genericNode/contentExchange/*.cc src/genericNode/contentExchange/static/*.cc src/genericNode/contentExchange/static/command/*.cc src/genericNode/contentExchange/static/handler/*.cc src/genericNode/contentExchange/static/message/*.cc src/genericNode/contentExchange/static/state/*.cc src/message/*.cc src/simulator/*.cc src/simulator/cache/*.cc src/simulator/coordinate/*.cc src/simulator/coordinate/command/*.cc src/simulator/coordinate/stats/*.cc src/simulator/execption/*.cc src/simulator/genericNode/*.cc src/simulator/genericNode/contentExchange/*.cc src/simulator/genericNode/contentExchange/static/*.cc src/simulator/genericNode/contentExchange/static/command/*.cc src/simulator/genericNode/contentExchange/static/handler/*.cc src/simulator/genericNode/contentExchange/static/message/*.cc src/simulator/genericNode/contentExchange/static/state/*.cc src/simulator/message/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/cache/InformationSet.o: src/cache/InformationSet.cc
$O/src/cache/MruCache.o: src/cache/MruCache.cc
$O/src/cache/LfuCache.o: src/cache/LfuCache.cc
$O/src/cache/LruCache.o: src/cache/LruCache.cc
$O/src/cache/Cache.o: src/cache/Cache.cc
$O/src/coordinate/CentralUnit.o: src/coordinate/CentralUnit.cc
$O/src/coordinate/CDN_RequestsAssignerReceiver.o: src/coordinate/CDN_RequestsAssignerReceiver.cc
$O/src/coordinate/CDN_CentralUnit.o: src/coordinate/CDN_CentralUnit.cc
$O/src/coordinate/CDN_CentralUnit_Reply.o: src/coordinate/CDN_CentralUnit_Reply.cc
$O/src/coordinate/command/CDN_Commands.o: src/coordinate/command/CDN_Commands.cc
$O/src/coordinate/command/Commands.o: src/coordinate/command/Commands.cc
$O/src/coordinate/stats/Stats.o: src/coordinate/stats/Stats.cc
$O/src/coordinate/stats/statistic.o: src/coordinate/stats/statistic.cc
$O/src/coordinate/stats/RequestLogEntry.o: src/coordinate/stats/RequestLogEntry.cc
$O/src/coordinate/stats/CacheLogEntry.o: src/coordinate/stats/CacheLogEntry.cc
$O/src/genericNode/PortNumberAllocator.o: src/genericNode/PortNumberAllocator.cc
$O/src/genericNode/contentExchange/ServerUnit.o: src/genericNode/contentExchange/ServerUnit.cc
$O/src/genericNode/contentExchange/AlternateServerDetector.o: src/genericNode/contentExchange/AlternateServerDetector.cc
$O/src/genericNode/contentExchange/ServicePeer.o: src/genericNode/contentExchange/ServicePeer.cc
$O/src/genericNode/contentExchange/ClientUnit.o: src/genericNode/contentExchange/ClientUnit.cc
$O/src/genericNode/contentExchange/Negotiator.o: src/genericNode/contentExchange/Negotiator.cc
$O/src/genericNode/contentExchange/RequestsAssignerReceiver.o: src/genericNode/contentExchange/RequestsAssignerReceiver.cc
$O/src/genericNode/contentExchange/StateTester.o: src/genericNode/contentExchange/StateTester.cc
$O/src/genericNode/contentExchange/static/StaticContentExchange_StateTester.o: src/genericNode/contentExchange/static/StaticContentExchange_StateTester.cc
$O/src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o: src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.cc \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o: src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.cc
$O/src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o: src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.cc
$O/src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o: src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.cc
$O/src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o: src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.cc
$O/src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o: src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.cc \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o: src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.cc
$O/src/genericNode/contentExchange/static/command/Command.o: src/genericNode/contentExchange/static/command/Command.cc
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.cc
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.cc
$O/src/genericNode/contentExchange/static/handler/DownloadersBase.o: src/genericNode/contentExchange/static/handler/DownloadersBase.cc
$O/src/genericNode/contentExchange/static/handler/Handler.o: src/genericNode/contentExchange/static/handler/Handler.cc
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/genericNode/contentExchange/static/message/StaticObject.o: src/genericNode/contentExchange/static/message/StaticObject.cc
$O/src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o: src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.cc
$O/src/genericNode/contentExchange/static/message/ServableItem.o: src/genericNode/contentExchange/static/message/ServableItem.cc
$O/src/genericNode/contentExchange/static/message/StaticObjectMessage.o: src/genericNode/contentExchange/static/message/StaticObjectMessage.cc
$O/src/genericNode/contentExchange/static/state/State.o: src/genericNode/contentExchange/static/state/State.cc
$O/src/genericNode/contentExchange/static/state/StaticContentExchange_State.o: src/genericNode/contentExchange/static/state/StaticContentExchange_State.cc
$O/src/message/RequestMessage.o: src/message/RequestMessage.cc
$O/src/message/RequestMessage_Base_m.o: src/message/RequestMessage_Base_m.cc
$O/src/message/InterNodeRequestProtocol.o: src/message/InterNodeRequestProtocol.cc
$O/src/message/Request.o: src/message/Request.cc
$O/src/simulator/cache/LruCache.o: src/simulator/cache/LruCache.cc
$O/src/simulator/cache/Cache.o: src/simulator/cache/Cache.cc
$O/src/simulator/cache/MruCache.o: src/simulator/cache/MruCache.cc
$O/src/simulator/cache/LfuCache.o: src/simulator/cache/LfuCache.cc
$O/src/simulator/cache/InformationSet.o: src/simulator/cache/InformationSet.cc
$O/src/simulator/coordinate/CDN_CentralUnit.o: src/simulator/coordinate/CDN_CentralUnit.cc
$O/src/simulator/coordinate/CDN_CentralUnit_Reply.o: src/simulator/coordinate/CDN_CentralUnit_Reply.cc
$O/src/simulator/coordinate/CentralUnit.o: src/simulator/coordinate/CentralUnit.cc
$O/src/simulator/coordinate/CDN_RequestsAssignerReceiver.o: src/simulator/coordinate/CDN_RequestsAssignerReceiver.cc
$O/src/simulator/coordinate/command/CDN_Commands.o: src/simulator/coordinate/command/CDN_Commands.cc
$O/src/simulator/coordinate/command/Commands.o: src/simulator/coordinate/command/Commands.cc
$O/src/simulator/coordinate/stats/statistic.o: src/simulator/coordinate/stats/statistic.cc
$O/src/simulator/coordinate/stats/Stats.o: src/simulator/coordinate/stats/Stats.cc
$O/src/simulator/coordinate/stats/RequestLogEntry.o: src/simulator/coordinate/stats/RequestLogEntry.cc
$O/src/simulator/coordinate/stats/CacheLogEntry.o: src/simulator/coordinate/stats/CacheLogEntry.cc
$O/src/simulator/genericNode/PortNumberAllocator.o: src/simulator/genericNode/PortNumberAllocator.cc
$O/src/simulator/genericNode/contentExchange/ClientUnit.o: src/simulator/genericNode/contentExchange/ClientUnit.cc
$O/src/simulator/genericNode/contentExchange/ServerUnit.o: src/simulator/genericNode/contentExchange/ServerUnit.cc
$O/src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.o: src/simulator/genericNode/contentExchange/RequestsAssignerReceiver.cc
$O/src/simulator/genericNode/contentExchange/Negotiator.o: src/simulator/genericNode/contentExchange/Negotiator.cc
$O/src/simulator/genericNode/contentExchange/ServicePeer.o: src/simulator/genericNode/contentExchange/ServicePeer.cc
$O/src/simulator/genericNode/contentExchange/AlternateServerDetector.o: src/simulator/genericNode/contentExchange/AlternateServerDetector.cc
$O/src/simulator/genericNode/contentExchange/StateTester.o: src/simulator/genericNode/contentExchange/StateTester.cc
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.cc \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.cc
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_StateTester.cc
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.cc
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.cc \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.cc
$O/src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o: src/simulator/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.cc
$O/src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o: src/simulator/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.cc
$O/src/simulator/genericNode/contentExchange/static/command/Command.o: src/simulator/genericNode/contentExchange/static/command/Command.cc
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.cc
$O/src/simulator/genericNode/contentExchange/static/handler/Handler.o: src/simulator/genericNode/contentExchange/static/handler/Handler.cc
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.o: src/simulator/genericNode/contentExchange/static/handler/DownloadersBase.cc
$O/src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o: src/simulator/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.cc
$O/src/simulator/genericNode/contentExchange/static/message/StaticObject.o: src/simulator/genericNode/contentExchange/static/message/StaticObject.cc
$O/src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.o: src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage.cc
$O/src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o: src/simulator/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.cc
$O/src/simulator/genericNode/contentExchange/static/message/ServableItem.o: src/simulator/genericNode/contentExchange/static/message/ServableItem.cc
$O/src/simulator/genericNode/contentExchange/static/state/State.o: src/simulator/genericNode/contentExchange/static/state/State.cc
$O/src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.o: src/simulator/genericNode/contentExchange/static/state/StaticContentExchange_State.cc
$O/src/simulator/message/RequestMessage_Base_m.o: src/simulator/message/RequestMessage_Base_m.cc
$O/src/simulator/message/RequestMessage.o: src/simulator/message/RequestMessage.cc
$O/src/simulator/message/Request.o: src/simulator/message/Request.cc
$O/src/simulator/message/InterNodeRequestProtocol.o: src/simulator/message/InterNodeRequestProtocol.cc

