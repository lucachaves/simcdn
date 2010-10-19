#
# OMNeT++/OMNEST Makefile for CDNRef
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I../inet/src/networklayer/common -I../inet/src/networklayer/rsvp_te -I../inet/src/networklayer/icmpv6 -I../inet/src/transport/tcp -I../inet/src/networklayer/mpls -I../inet/src/networklayer/ted -I../inet/src/networklayer/contract -I../inet/src/util -I../inet/src/transport/contract -I../inet/src/linklayer/mfcore -I../inet/src/networklayer/ldp -I../inet/src/networklayer/ipv4 -I../inet/src/base -I../inet/src/util/headerserializers -I../inet/src/networklayer/ipv6 -I../inet/src/transport/sctp -I../inet/src/world -I../inet/src/applications/pingapp -I../inet/src/linklayer/contract -I../inet/src/networklayer/arp -I../inet/src/transport/udp -L../inet/out/$(CONFIGNAME)/src -linet -KINET_PROJ=../inet
#

# Name of target to be created (-o option)
TARGET = CDNRef$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../inet/src/networklayer/common \
    -I../inet/src/networklayer/rsvp_te \
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
    -Imodels/teste/stats \
    -Isrc \
    -Isrc/cache \
    -Isrc/coordinate \
    -Isrc/coordinate/command \
    -Isrc/coordinate/stats \
    -Isrc/execption \
    -Isrc/genericNode \
    -Isrc/genericNode/contentExchange \
    -Isrc/genericNode/contentExchange/static \
    -Isrc/genericNode/contentExchange/static/command \
    -Isrc/genericNode/contentExchange/static/handler \
    -Isrc/genericNode/contentExchange/static/message \
    -Isrc/genericNode/contentExchange/static/state \
    -Isrc/message

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
    $O/src/cache/Cache.o \
    $O/src/cache/LfuCache.o \
    $O/src/cache/MruCache.o \
    $O/src/cache/LruCache.o \
    $O/src/cache/InformationSet.o \
    $O/src/coordinate/CDN_RequestsAssignerReceiver.o \
    $O/src/coordinate/CDN_CentralUnit.o \
    $O/src/coordinate/CentralUnit.o \
    $O/src/coordinate/CDN_CentralUnit_Reply.o \
    $O/src/coordinate/command/Commands.o \
    $O/src/coordinate/command/CDN_Commands.o \
    $O/src/coordinate/stats/statistic.o \
    $O/src/coordinate/stats/CacheLogEntry.o \
    $O/src/coordinate/stats/RequestLogEntry.o \
    $O/src/coordinate/stats/Stats.o \
    $O/src/genericNode/PortNumberAllocator.o \
    $O/src/genericNode/contentExchange/Negotiator.o \
    $O/src/genericNode/contentExchange/AlternateServerDetector.o \
    $O/src/genericNode/contentExchange/ServerUnit.o \
    $O/src/genericNode/contentExchange/ServicePeer.o \
    $O/src/genericNode/contentExchange/ClientUnit.o \
    $O/src/genericNode/contentExchange/RequestsAssignerReceiver.o \
    $O/src/genericNode/contentExchange/StateTester.o \
    $O/src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o \
    $O/src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o \
    $O/src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o \
    $O/src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o \
    $O/src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o \
    $O/src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o \
    $O/src/genericNode/contentExchange/static/StaticContentExchange_StateTester.o \
    $O/src/genericNode/contentExchange/static/command/Command.o \
    $O/src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o \
    $O/src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o \
    $O/src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o \
    $O/src/genericNode/contentExchange/static/handler/DownloadersBase.o \
    $O/src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o \
    $O/src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o \
    $O/src/genericNode/contentExchange/static/handler/Handler.o \
    $O/src/genericNode/contentExchange/static/message/StaticObject.o \
    $O/src/genericNode/contentExchange/static/message/ServableItem.o \
    $O/src/genericNode/contentExchange/static/message/StaticObjectMessage.o \
    $O/src/genericNode/contentExchange/static/state/StaticContentExchange_State.o \
    $O/src/genericNode/contentExchange/static/state/State.o \
    $O/src/message/RequestMessage.o \
    $O/src/message/Request.o \
    $O/src/message/InterNodeRequestProtocol.o \
    $O/src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o \
    $O/src/message/RequestMessage_Base_m.o

# Message files
MSGFILES = \
    src/genericNode/contentExchange/static/message/StaticObjectMessage_Base.msg \
    src/message/RequestMessage_Base.msg

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
	-rm -f src/*_m.cc src/*_m.h
	-rm -f src/cache/*_m.cc src/cache/*_m.h
	-rm -f src/coordinate/*_m.cc src/coordinate/*_m.h
	-rm -f src/coordinate/command/*_m.cc src/coordinate/command/*_m.h
	-rm -f src/coordinate/stats/*_m.cc src/coordinate/stats/*_m.h
	-rm -f src/execption/*_m.cc src/execption/*_m.h
	-rm -f src/genericNode/*_m.cc src/genericNode/*_m.h
	-rm -f src/genericNode/contentExchange/*_m.cc src/genericNode/contentExchange/*_m.h
	-rm -f src/genericNode/contentExchange/static/*_m.cc src/genericNode/contentExchange/static/*_m.h
	-rm -f src/genericNode/contentExchange/static/command/*_m.cc src/genericNode/contentExchange/static/command/*_m.h
	-rm -f src/genericNode/contentExchange/static/handler/*_m.cc src/genericNode/contentExchange/static/handler/*_m.h
	-rm -f src/genericNode/contentExchange/static/message/*_m.cc src/genericNode/contentExchange/static/message/*_m.h
	-rm -f src/genericNode/contentExchange/static/state/*_m.cc src/genericNode/contentExchange/static/state/*_m.h
	-rm -f src/message/*_m.cc src/message/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc cache/*.cc coordinate/*.cc coordinate/command/*.cc coordinate/stats/*.cc execption/*.cc genericNode/*.cc genericNode/contentExchange/*.cc genericNode/contentExchange/static/*.cc genericNode/contentExchange/static/command/*.cc genericNode/contentExchange/static/handler/*.cc genericNode/contentExchange/static/message/*.cc genericNode/contentExchange/static/state/*.cc message/*.cc models/*.cc models/RNP/*.cc models/RNP/caches/*.cc models/RNP/dataset/*.cc models/RNP/results/*.cc models/RNP/stats/*.cc models/RNP_LAYOUT_1/*.cc models/RNP_LAYOUT_2/*.cc models/_batch/*.cc models/_stats/*.cc models/exp01/*.cc models/exp01/caches/*.cc models/exp01/dataset/*.cc models/exp01/results/*.cc models/exp01/stats/*.cc models/exp02/*.cc models/exp02/caches/*.cc models/exp02/dataset/*.cc models/exp02/stats/*.cc models/exp11/*.cc models/exp11/caches/*.cc models/exp11/dataset/*.cc models/exp11/results/*.cc models/exp11/stats/*.cc models/exp12/*.cc models/exp12/caches/*.cc models/exp12/dataset/*.cc models/exp12/results/*.cc models/exp12/stats/*.cc models/nHost/*.cc models/nHost/caches/*.cc models/nHost/dataset/*.cc models/nHost/results/*.cc models/nHost/stats/*.cc models/simpleCDN/*.cc models/simpleCDN/caches/*.cc models/simpleCDN/dataset/*.cc models/simpleCDN/results/*.cc models/simpleCDN/stats/*.cc models/teste/*.cc models/teste/caches/*.cc models/teste/dataset/*.cc models/teste/results/*.cc models/teste/stats/*.cc src/*.cc src/cache/*.cc src/coordinate/*.cc src/coordinate/command/*.cc src/coordinate/stats/*.cc src/execption/*.cc src/genericNode/*.cc src/genericNode/contentExchange/*.cc src/genericNode/contentExchange/static/*.cc src/genericNode/contentExchange/static/command/*.cc src/genericNode/contentExchange/static/handler/*.cc src/genericNode/contentExchange/static/message/*.cc src/genericNode/contentExchange/static/state/*.cc src/message/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/cache/InformationSet.o: src/cache/InformationSet.cc \
	src/cache/InformationSet.h
$O/src/cache/MruCache.o: src/cache/MruCache.cc \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/cache/MruCache.h \
	src/execption/Exceptions.h \
	src/cache/AnakreonCommon.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/cache/InformationSet.h
$O/src/cache/LfuCache.o: src/cache/LfuCache.cc \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/cache/LfuCache.h \
	src/execption/Exceptions.h \
	src/cache/AnakreonCommon.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/cache/InformationSet.h
$O/src/cache/LruCache.o: src/cache/LruCache.cc \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/cache/LruCache.h \
	src/execption/Exceptions.h \
	src/cache/AnakreonCommon.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/cache/InformationSet.h
$O/src/cache/Cache.o: src/cache/Cache.cc \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/cache/Cache.h \
	src/cache/InformationSet.h
$O/src/coordinate/CentralUnit.o: src/coordinate/CentralUnit.cc \
	src/coordinate/CentralUnit.h
$O/src/coordinate/CDN_RequestsAssignerReceiver.o: src/coordinate/CDN_RequestsAssignerReceiver.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/command/Commands.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/cache/InformationSet.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/coordinate/command/CDN_Commands.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/coordinate/CDN_CentralUnit.o: src/coordinate/CDN_CentralUnit.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/coordinate/CDN_CentralUnit_Reply.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/command/Commands.h \
	src/cache/Cache.h \
	src/coordinate/CDN_CentralUnit.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/command/CDN_Commands.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/coordinate/CDN_CentralUnit_Reply.o: src/coordinate/CDN_CentralUnit_Reply.cc \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/coordinate/CDN_CentralUnit_Reply.h
$O/src/coordinate/command/CDN_Commands.o: src/coordinate/command/CDN_Commands.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/cache/AnakreonCommon.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/coordinate/stats/LogEntry.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/execption/Exceptions.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/command/CDN_Commands.h \
	src/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/command/Commands.h
$O/src/coordinate/command/Commands.o: src/coordinate/command/Commands.cc \
	src/coordinate/command/Commands.h
$O/src/coordinate/stats/Stats.o: src/coordinate/stats/Stats.cc \
	src/coordinate/stats/LogEntry.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/coordinate/stats/Stats.h
$O/src/coordinate/stats/statistic.o: src/coordinate/stats/statistic.cc \
	src/coordinate/stats/statistic.h
$O/src/coordinate/stats/RequestLogEntry.o: src/coordinate/stats/RequestLogEntry.cc \
	src/coordinate/stats/LogEntry.h \
	src/coordinate/stats/RequestLogEntry.h
$O/src/coordinate/stats/CacheLogEntry.o: src/coordinate/stats/CacheLogEntry.cc \
	src/coordinate/stats/LogEntry.h \
	src/coordinate/stats/CacheLogEntry.h
$O/src/genericNode/PortNumberAllocator.o: src/genericNode/PortNumberAllocator.cc \
	src/execption/Exceptions.h
$O/src/genericNode/contentExchange/ServerUnit.o: src/genericNode/contentExchange/ServerUnit.cc \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/AlternateServerDetector.o: src/genericNode/contentExchange/AlternateServerDetector.cc \
	src/genericNode/contentExchange/AlternateServerDetector.h
$O/src/genericNode/contentExchange/ServicePeer.o: src/genericNode/contentExchange/ServicePeer.cc \
	src/genericNode/contentExchange/ServicePeer.h
$O/src/genericNode/contentExchange/ClientUnit.o: src/genericNode/contentExchange/ClientUnit.cc \
	src/genericNode/contentExchange/ClientUnit.h
$O/src/genericNode/contentExchange/Negotiator.o: src/genericNode/contentExchange/Negotiator.cc \
	src/genericNode/contentExchange/Negotiator.h
$O/src/genericNode/contentExchange/RequestsAssignerReceiver.o: src/genericNode/contentExchange/RequestsAssignerReceiver.cc \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h
$O/src/genericNode/contentExchange/StateTester.o: src/genericNode/contentExchange/StateTester.cc \
	src/genericNode/contentExchange/StateTester.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_StateTester.o: src/genericNode/contentExchange/static/StaticContentExchange_StateTester.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/command/CDN_Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.o: src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/cache/InformationSet.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/command/CDN_Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.o: src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/coordinate/CDN_CentralUnit_Reply.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/cache/InformationSet.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/coordinate/stats/Stats.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/command/CDN_Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.o: src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/genericNode/contentExchange/Negotiator.h \
	src/coordinate/command/CDN_Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.o: src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/coordinate/CDN_CentralUnit_Reply.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/cache/Cache.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/InformationSet.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/genericNode/contentExchange/Negotiator.h \
	src/coordinate/command/CDN_Commands.h \
	src/genericNode/contentExchange/static/state/State.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.o: src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/coordinate/stats/Stats.h \
	src/cache/InformationSet.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/command/CDN_Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.o: src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/cache/MruCache.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/cache/InformationSet.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/cache/LfuCache.h \
	src/cache/LruCache.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/command/CDN_Commands.h \
	src/genericNode/contentExchange/static/state/State.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.o: src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.cc \
	src/coordinate/stats/LogEntry.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/genericNode/contentExchange/static/command/Command.h
$O/src/genericNode/contentExchange/static/command/Command.o: src/genericNode/contentExchange/static/command/Command.cc \
	src/genericNode/contentExchange/static/command/Command.h
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.cc \
	src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPServerHandler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	src/coordinate/command/Commands.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	src/cache/LruCache.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/ServerUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	src/coordinate/command/CDN_Commands.h \
	src/genericNode/contentExchange/static/state/State.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.cc \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPClientHandler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/coordinate/command/Commands.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/genericNode/contentExchange/Negotiator.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/ServerUnit.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/genericNode/contentExchange/static/state/State.h \
	src/coordinate/command/CDN_Commands.h
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.cc \
	src/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	src/coordinate/command/Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/cache/Cache.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/genericNode/contentExchange/Negotiator.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/command/CDN_Commands.h \
	src/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/genericNode/contentExchange/static/state/State.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/genericNode/contentExchange/ServerUnit.h
$O/src/genericNode/contentExchange/static/handler/DownloadersBase.o: src/genericNode/contentExchange/static/handler/DownloadersBase.cc \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	src/coordinate/command/Commands.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/genericNode/contentExchange/Negotiator.h \
	src/coordinate/stats/RequestLogEntry.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/genericNode/contentExchange/ServerUnit.h \
	src/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/coordinate/stats/Stats.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	src/coordinate/command/CDN_Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/genericNode/contentExchange/static/state/State.h
$O/src/genericNode/contentExchange/static/handler/Handler.o: src/genericNode/contentExchange/static/handler/Handler.cc \
	src/coordinate/stats/LogEntry.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/command/Command.h
$O/src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.o: src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.cc \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientUnit.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ClientNegotiator.h \
	src/coordinate/stats/LogEntry.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServicePeer.h \
	src/genericNode/contentExchange/static/handler/StaticContentExchange_TCPClientHandler.h \
	src/coordinate/command/Commands.h \
	src/cache/Cache.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerUnit.h \
	src/cache/InformationSet.h \
	src/genericNode/contentExchange/static/StaticContentExchange_AlternateServerDetector.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/transport/contract/TCPCommand_m.h \
	src/genericNode/contentExchange/static/handler/StaticContentExchange_UDPServerHandler.h \
	src/genericNode/contentExchange/static/StaticContentExchange_ServerNegotiator.h \
	src/genericNode/contentExchange/static/StaticContentExchange_StateTester.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	src/coordinate/CentralUnit.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	src/cache/LruCache.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/genericNode/contentExchange/Negotiator.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/ServerUnit.h \
	$(INET_PROJ)/src/transport/contract/TCPSocketMap.h \
	src/genericNode/contentExchange/static/handler/DownloadersBase.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/message/InterNodeRequestProtocol.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	$(INET_PROJ)/src/transport/contract/TCPSocket.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/StateTester.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/genericNode/contentExchange/ClientUnit.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/coordinate/CDN_CentralUnit.h \
	src/coordinate/stats/Stats.h \
	src/coordinate/stats/CacheLogEntry.h \
	src/genericNode/contentExchange/ServicePeer.h \
	src/coordinate/CDN_RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/AlternateServerDetector.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/genericNode/contentExchange/RequestsAssignerReceiver.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	src/execption/Exceptions.h \
	src/coordinate/command/CDN_Commands.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	src/genericNode/contentExchange/static/state/State.h
$O/src/genericNode/contentExchange/static/message/StaticObject.o: src/genericNode/contentExchange/static/message/StaticObject.cc \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/genericNode/contentExchange/static/message/StaticObject.h
$O/src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.o: src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.cc \
	src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h
$O/src/genericNode/contentExchange/static/message/ServableItem.o: src/genericNode/contentExchange/static/message/ServableItem.cc \
	src/genericNode/contentExchange/static/message/ServableItem.h
$O/src/genericNode/contentExchange/static/message/StaticObjectMessage.o: src/genericNode/contentExchange/static/message/StaticObjectMessage.cc \
	src/coordinate/stats/LogEntry.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage_Base_m.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/message/StaticObjectMessage.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/genericNode/contentExchange/static/command/Command.h
$O/src/genericNode/contentExchange/static/state/State.o: src/genericNode/contentExchange/static/state/State.cc \
	src/genericNode/contentExchange/static/state/State.h \
	src/cache/InformationSet.h
$O/src/genericNode/contentExchange/static/state/StaticContentExchange_State.o: src/genericNode/contentExchange/static/state/StaticContentExchange_State.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	src/genericNode/contentExchange/static/state/StaticContentExchange_State.h \
	src/genericNode/contentExchange/static/handler/Handler.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/genericNode/contentExchange/static/command/StaticContentExchange_ServicePeerCommand.h \
	src/genericNode/contentExchange/static/message/StaticObject.h \
	src/genericNode/contentExchange/static/command/Command.h \
	src/coordinate/stats/LogEntry.h \
	$(INET_PROJ)/src/transport/tcp/TCP.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	src/execption/Exceptions.h \
	$(INET_PROJ)/src/transport/udp/UDP.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/state/State.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	src/cache/Cache.h \
	src/cache/InformationSet.h
$O/src/message/RequestMessage.o: src/message/RequestMessage.cc \
	src/coordinate/stats/LogEntry.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/message/RequestMessage.h \
	src/message/RequestMessage_Base_m.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/command/Command.h
$O/src/message/RequestMessage_Base_m.o: src/message/RequestMessage_Base_m.cc \
	src/message/RequestMessage_Base_m.h
$O/src/message/InterNodeRequestProtocol.o: src/message/InterNodeRequestProtocol.cc \
	src/coordinate/stats/LogEntry.h \
	src/message/Request.h \
	src/message/RequestMessage.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/message/RequestMessage_Base_m.h \
	src/message/InterNodeRequestProtocol.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/command/Command.h
$O/src/message/Request.o: src/message/Request.cc \
	src/coordinate/stats/LogEntry.h \
	src/message/Request.h \
	src/genericNode/contentExchange/static/message/ServableItem.h \
	src/coordinate/stats/RequestLogEntry.h \
	src/genericNode/contentExchange/static/command/Command.h

