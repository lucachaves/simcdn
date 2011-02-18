import os
import re
import random
import math
import wx


class BottleAttributes:
	bottlePath = None
	libsPath = None
	statsPath = None
	datasetPath = None
	networkPath = None
	objectsReference = {}
	surrogatesIds = None
	cachesPath = None
	surrogatesCaches = {}
	originsIds = None
	clientIds = None
	totalWebSiteSize = 0
	allObjectIds = []
	nRetries = None
	mean = None
	
	def reset(self):
		self.bottlePath = None
		self.libsPath = None
		self.statsPath = None
		self.datasetPath = None
		self.networkPath = None
		self.objectsReference = {}
		self.surrogatesIds = None
		self.cachesPath = None
		self.surrogatesCaches = {}
		self.originsIds = None
		self.clientIds = None
		self.totalWebSiteSize = 0
		self.allObjectIds = []
		self.nRetries = None
		self.mean = None
		

bottleAttributes = BottleAttributes()

def compareRequestsByTime(req1, req2):
	pat = re.compile("[+]?(\d+(\.\d*)?|\d*\.\d+)([eE][+]?\d+)?(\ +)(\d+)")
	patRes1 = pat.match(req1)
	patRes2 = pat.match(req2)

	return int(float(patRes1.group(1)) - float(patRes2.group(1)))

def processAndSaveTraffic(parent, clients, traffic):
	#open file
	try:
		fin = open(traffic, 'r')
	except:
		showSomeError(parent, "Error: While opening file: <" + traffic + ">")
		return 1

	#parse file to check format
	#build a reference e.g. clientsReference[234234] = 234234
	clientsReference = {}
	pat = re.compile("[+]?(\d+(\.\d*)?|\d*\.\d+)([eE][+]?\d+)?(\ +)(\d+)(\ +)[+]?(\d+(\.\d*)?|\d*\.\d+)([eE][+]?\d+)?")
	for line in fin:
		#print line
		patRes = pat.match(line)
		if patRes == None:
			showSomeError(parent, "invalid traffic file format")
			return 1
		clientsReference[int(patRes.group(5))] = int(patRes.group(5))

	#check if the client the user provided and the clients in the trace file are the same in  number
	processTraffic = False
	if(len(clientsReference) != clients):
		#showSomeError(parent,"clients number mishmatch between traffic and user declared\nWill process file.")
		print "Clients in trace are diffent in number than the option.\nWill randomly re-assign clients in traffic."
		processTraffic = True
		#return 1

	#check that the ids mach the increasing number of the user supplied number of clients
	if not processTraffic:
		for i in range(0, clients):
			try:
				dummy = clientsReference[i]
			except:
				#showSomeError(parent,"clients ids mishmatch between traffic and user declared\nWill process file.")
				print "Clients in trace are diffent in number than the option.\nWill randomly re-assign clients in traffic."
				processTraffic = True
				#return 1

	distributedTraffic = {}
	for i in range(0, clients):
		distributedTraffic[i] = []

	fin.seek(0)
	for line in fin:
		patRes = pat.match(line)
		if patRes == None:
			showSomeError(parent, "invalid traffic file format")
			return 1
		#HACK:
		#if processTraffic:
		#	distributedTraffic[    random.randint(0, clients - 1)   ] += [patRes.group(1) + ' ' + patRes.group(7) + '\n']
		#else:
		##print patRes.group(5)+"->"+patRes.group(1) + ' ' + patRes.group(7) + ' u\n'
		distributedTraffic[     clientsReference[int(patRes.group(5))]   ] += [patRes.group(1) + ' ' + patRes.group(7) + ' u\n']

	for key in distributedTraffic.keys():
		distributedTraffic[key].sort(compareRequestsByTime)

	#dump files
	for key in distributedTraffic.keys():
		try:
			fout = open(bottleAttributes.datasetPath + '/' + str(bottleAttributes.clientIds[key]), 'w')
		except:
			showSomeError(parent, "error while saving traffic for clients")
			return 1
		for line in distributedTraffic[key]:
			fout.write(line)
		fout.close()



	fin.close()
	return 0

def showSomeError(parent, error):
	d = wx.MessageDialog(parent, error, "ERROR", wx.OK | wx.ICON_HAND, wx.DefaultPosition)
	d.ShowModal() # Shows it
	d.Destroy() # finally destroy it when finished.
	return 0

def verifyObjectsFile(parent, file):
	try:
		fin = open(file, 'r')
	except:
		showSomeError(parent, "Error: While opening file: <" + file + ">")
		return 1


	patObjectsFile = re.compile("(\d+)(\ +)(\d+)")
	for line in fin:
		patRes = patObjectsFile.match(line)
		if patRes == None:
			showSomeError(parent, "Error: Invalid objects file format!")
			return 1
		bottleAttributes.objectsReference[int(patRes.group(1))] = int(patRes.group(3))
		bottleAttributes.totalWebSiteSize += int(patRes.group(3))
		bottleAttributes.allObjectIds += [ int(patRes.group(1)) ]

	for i in range(0, len(bottleAttributes.objectsReference)):
		try:
			dummy = bottleAttributes.objectsReference[i]
		except:
			showSomeError(parent, "Error: Invalid objects file format!")
			return 1
	fin.close()
	return 0

def prepareBottle(parent, options):
	#make the bottle directory
	bottleAttributes.bottlePath = options.outputDir + '/' + options.bottleName
	if not os.system("cd \"" + options.outputDir + "\"; [ -d \"" + options.bottleName + "\" ]"):
		showSomeError(parent, "A bottle with the same name already exists, remove it youself!\nBottle creation aborted")
		return 1
	if os.system('mkdir \"' + bottleAttributes.bottlePath + '\"'):
		showSomeError(parent, "Error creating bottle directory")
		return 1
	return 0

def prepareStats(parent, options):
	#prepare stats dir
	bottleAttributes.statsPath = bottleAttributes.bottlePath + '/stats'
	if os.system('mkdir \"' + bottleAttributes.statsPath + '\"'):
		showSomeError(parent, "Error creating statistics directory")
		return 1
	return 0

def prepareDataset(parent, options):
	bottleAttributes.datasetPath = bottleAttributes.bottlePath + '/dataset'
	if os.system('mkdir \"' + bottleAttributes.datasetPath + '\"'):
		showSomeError(parent, "Error creating dataset directory")
		return 1

	if os.system('cp \"' + options.objects + '\" \"' + bottleAttributes.datasetPath + '/objects\"'):
		showSomeError(parent, "Error copying objects, " + 'cp ' + options.objects + ' ' + bottleAttributes.datasetPath + '/objects')
		return 1

	if verifyObjectsFile(parent, bottleAttributes.datasetPath + '/objects'):
		return 1

	return processAndSaveTraffic(parent, options.clients, options.traffic)

def prepareNetwork(parent, options):
	#open file
	try:
		fin = open(options.routersGraphFile, 'r')
	except:
		showSomeError(parent, "Error: While routers file: <" + options.routersGraphFile + ">")
		return 1

	routersReference = {}
	pat = re.compile("(\d+)(\ +)(\d+)")
	for line in fin:
		patRes = pat.match(line)
		if patRes == None:
			showSomeError(parent, "Error: Invalid routers file format!")
			return 1
		routersReference[int(patRes.group(1))] = []
		routersReference[int(patRes.group(3))] = []

	fin.seek(0)
	nRouters = len(routersReference)
	routerIds = range(0, nRouters)
	for i in routerIds:
		try:
			dummy = routersReference[i]
		except:
			showSomeError(parent, "Error: Invalid routers file format!")
			return 1

	for line in fin:
		patRes = pat.match(line)
		if patRes == None:
			showSomeError(parent, "Error: Invalid routers file format!")
			return 1
		routersReference[int(patRes.group(1))] += [int(patRes.group(3))]

	for i in routerIds:
		try:
			set(routersReference[i])
			list(routersReference[i])
		except:
			showSomeError(parent, "Error: Invalid routers file format!")
			return 1
	fin.close()

	bottleAttributes.clientIds = range(nRouters, nRouters + options.clients)
	clientsReference = {}
	for i in bottleAttributes.clientIds:
		clientR = getRouter(options, i - nRouters, "clients")
		clientsReference[i] = clientR
		routersReference[clientR] += [i]


	#Surrogates
	bottleAttributes.surrogatesIds = range(nRouters + options.clients, nRouters + options.clients + options.surrogates)
	surrogatesReference = {}
	for i in bottleAttributes.surrogatesIds:
		surrogateR = getRouter(options, i - (nRouters + options.clients), "surrogates")
		surrogatesReference[i] = surrogateR
		routersReference[surrogateR] += [i]

	#Origim
	bottleAttributes.originsIds = range(nRouters + options.clients + options.surrogates, nRouters + options.clients + options.surrogates + options.origins)
	originsReference = {}
	for i in bottleAttributes.originsIds:
		originR = getRouter(options, i - (nRouters + options.clients + options.surrogates), "origins")
		originsReference[i] = originR
		routersReference[originR] += [i]

	try:
		fout = open(bottleAttributes.bottlePath + '/base.ned', 'w')
	except:
		showSomeError(parent, "error while saving network")
		return 1

	fout.write("package "+options.package+";\n")
	fout.write("""
import inet.world.ChannelInstaller;
import inet.networklayer.autorouting.FlatNetworkConfigurator;
import inet.nodes.inet.Router;
import inet.nodes.inet.StandardHost;
import ned.DatarateChannel;
import src.simulator.coordinate.CDN_CentralUnit;
import src.simulator.coordinate.stats.Stats;
import src.simulator.genericNode.GenericHost;

channel fiberline extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 100Mbps;
}
channel fiberline10G extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 10Gbps;
}
channel fiberline2G extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 2.5Gbps;
}
channel fiberline622M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 622Mbps;
}
channel fiberline155M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 155Mbps;
}
channel fiberline257M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 257Mbps;
}
channel fiberline34M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 34Mbps;
}
channel fiberline20M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 2Mbps;
}
channel fiberline6M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 6Mbps;
}
network base
{
    parameters:
        int n = default(10); // number of switch on the router
    submodules:
        channelInstaller: ChannelInstaller {
            parameters:
                channelClass = "ThruputMeteringChannel";
                channelAttrs = "format=u";
                @display("p=84,50;i=block/cogwheel");
        }
        configurator: FlatNetworkConfigurator {
            parameters:
                @display("p=185,50;i=block/cogwheel");
        }
        cdn_CentralUnit: CDN_CentralUnit {
            @display("p=382,50;i=block/cogwheel");
        }
        stats: Stats {
            @display("p=276,50;i=block/cogwheel");
        }
        """);

	for i in routerIds:
		fout.write("r" + str(i) + """: Router{
    		parameters:
                    @display("i=abstract/router");
        }
        """)

	for i in bottleAttributes.clientIds:
		fout.write("c" + str(i) + """: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        """)

	for i in bottleAttributes.surrogatesIds:
		fout.write("s" + str(i) + """: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	""")

	for i in bottleAttributes.originsIds:
		fout.write("o" + str(i) + """: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	""")
	fout.write("connections allowunconnected:\n")      
	for i in routersReference.keys():
		for k in routersReference[i]:
			if k in routerIds:
				fout.write("\t\tr" + str(i) + ".pppg++ <--> " + str(getFiberLineName(options, i, k)) + " <--> r" + str(k) + ".pppg++;\n")                
			elif k in bottleAttributes.clientIds:
				fout.write("\t\tr" + str(i) + ".pppg++ <--> fiberline <--> c" + str(k) + ".pppg++;\n")
			elif k in bottleAttributes.surrogatesIds:
				fout.write("\t\tr" + str(i) + ".pppg++ <--> fiberline <--> s" + str(k) + ".pppg++;\n")
			elif k in bottleAttributes.originsIds:
				fout.write("\t\tr" + str(i) + ".pppg++ <--> fiberline <--> o" + str(k) + ".pppg++;\n")
	fout.write("}")
	fout.close()


def verifyCacheContentFile(parent, file, cacheSize):
	try:
		fin = open(file, 'r')
	except:
		showSomeError(parent, "Error: While opening file: <" + file + ">")
		return 1

	currentSize = 0
	patObjectsFile = re.compile("(\d+)")
	for line in fin:
		patRes = patObjectsFile.match(line)
		if patRes == None:
			showSomeError(parent, "Error: Invalid objects file format!")
			return 1
		try:
			currentSize += bottleAttributes.objectsReference[int(patRes.group(1))]
		except:
			showSomeError(parent, "Error: Detected object that do not exist in reference!")
			return 1

	if currentSize > cacheSize:
		showSomeError(parent, "Error: Objects do not fit in cache!")
		return 1

	fin.close()


def prepareCaches(parent, options):
	bottleAttributes.cachesPath = bottleAttributes.bottlePath + "/caches"
	if os.system("mkdir \"" + bottleAttributes.cachesPath + '\"'):
		showSomeError(parent, "Error creating caches directory")
		return 1
	try:
		fin = open(options.placement, 'r')
	except:
		showSomeError(parent, "Error: While opening file: <" + options.placement + ">")
		return 1

	expectedSurrogatesRange = range(0, options.surrogates)

	patInt = re.compile("(\d+)")
	patDouble = re.compile("[+]?(\d+(\.\d*)?|\d*\.\d+)([eE][+]?\d+)?")

	while True:
		#read surrogate index
		line = fin.readline()
		if line == "":
			break


		patRes = patInt.match(line)
		if patRes == None:
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected surrogate index")
			return 1
		currentSurrogateIndex = int(patRes.group(1))

		if currentSurrogateIndex not in expectedSurrogatesRange:
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected surrogate index in the range [0 -numberOfSurrogateServer)")
			return 1

		#read number of caches
		line = fin.readline()
		if line == "":
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected number of caches")
			return 1

		patRes = patInt.match(line)
		if patRes == None:
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected number of caches")
			return 1
		numberOfCaches = int(patRes.group(1))
		if numberOfCaches != 1:
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected number of cache = 1")
			return 1

		#read file that contains objects
		line = fin.readline()
		if line == "":
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected surrogate index")
			return 1

		if '\n' in line:
			line = line[:len(line) - 1]

		file = line

		#read cache type
		line = fin.readline()
		if line == "":
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected cache type")
			return 1

		if '\n' in line:
			line = line[:len(line) - 1]

		cacheType = line
		cacheType = options.cacheType

		#read cache size in bytes
		line = fin.readline()
		if line == "":
			return 1

		patRes = patDouble.match(line)
		if patRes == None:
			showSomeError(parent, "Error: While reading placement file, invalid file format. Excpected cache size")
			return 1
		cacheSize = float(patRes.group(1))
		cacheSize = options.cacheSize

		if(file != "NULL"):
			#verify that the file has proper format and that it fits in cache
			if verifyCacheContentFile(parent, os.path.join(options.placementDir, file), cacheSize):
				return 1

			if os.system("cp \"" + os.path.join(options.placementDir, file) + "\" \"" + bottleAttributes.cachesPath + "/" + str(bottleAttributes.surrogatesIds[currentSurrogateIndex]) + '\"'):
				showSomeError(parent, "Error: While copying placement file " + os.path.join(options.placementDir, file) + " to " + bottleAttributes.cachesPath + "/" + str(bottleAttributes.surrogatesIds[currentSurrogateIndex]))
				return 1
		else:
			if os.system("touch \"" + bottleAttributes.cachesPath + "/" + str(bottleAttributes.surrogatesIds[currentSurrogateIndex]) + '\"'):
				showSomeError(parent, "Error: While copying placement file " + os.path.join(options.placementDir, file) + " to " + bottleAttributes.cachesPath + "/" + str(bottleAttributes.surrogatesIds[currentSurrogateIndex]))
				return 1

		bottleAttributes.surrogatesCaches[bottleAttributes.surrogatesIds[currentSurrogateIndex]] = ["./caches/" + str(bottleAttributes.surrogatesIds[currentSurrogateIndex]), cacheType, cacheSize]


	#if len(expectedSurrogatesRange) != 0:
	#	showSomeError(parent, "Error: While reading placement file, invalid file format. Not all surrogates' caches are configured")
	#	return 1

	fin.close()

def prepareInis(parent, options):
	try:
		fout = open(bottleAttributes.bottlePath + '/' + "omnetpp.ini", 'w')        
	except:
		showSomeError(parent, "error while creating omnetpp.ini")
		return 1
	fout.write(
"""
[General]

network = base


**.downloaderClass="DownloadersBase"
**.result-recording-modes = all

# tcp settings


**.tcp.mss = """)

	fout.write(str(1 * 1024))
	fout.write("\n")
	fout.write("**.tcp.advertisedWindow = ")
	fout.write(str(1 * 14 * 1024))
	fout.write("\n")
	fout.write("""
**.tcp.tcpAlgorithmClass="TCPReno"
**.tcp.recordStats=false
**.tcp.sendQueueClass="TCPMsgBasedSendQueue"
**.tcp.receiveQueueClass="TCPMsgBasedRcvQueue"

# ip settings
**.routingFile=""
**.ip.procDelay=10us
**.IPForward=false

# ARP configuration
**.arp.retryCount = 3
**.networkLayer.proxyARP = true  # Host's is hardwired "false"

# NIC configuration
**.ppp[*].queueType = "DropTailQueue" # in routers
**.ppp[*].queue.frameCapacity = 10  # in routers


""")
	fout.write("\n\n**.cdn_RequestsAssignerReceiver.nRetries=" + str(options.nRetries) + "\n**.cdn_RequestsAssignerReceiver.mean=" + str(options.mean)+ "\n")

	#set up surrogates
	for key in bottleAttributes.surrogatesCaches.keys():
		fout.write("**.s" + str(key) + ".cdn_RequestsAssignerReceiver.commandsScript = \"NULL\"\n")
		fout.write("**.s" + str(key) + ".staticContentExchange_ServicePeer.cacheType = \"" + bottleAttributes.surrogatesCaches[key][1] + "\"\n")
		if options.shrink is True:
			fout.write("**.s" + str(key) + ".staticContentExchange_ServicePeer.shrink = 1\n")
		else:
			fout.write("**.s" + str(key) + ".staticContentExchange_ServicePeer.shrink = 0\n")
		fout.write("**.s" + str(key) + ".staticContentExchange_ServicePeer.cacheContents = \"" + bottleAttributes.surrogatesCaches[key][0] + "\"\n")
		fout.write("**.s" + str(key) + ".staticContentExchange_ServicePeer.cacheSizeInMbs = \"" + str(math.ceil(((bottleAttributes.surrogatesCaches[key][2] / 1024.0) / 1024.0))) + "\"\n")

		fout.write("**.s" + str(key) + ".staticContentExchange_ServicePeer.objectsReference = \"./dataset/objects\"\n")
		fout.write("**.s" + str(key) + ".nServerHandlers = " + str(options.surrogatesIn) + "\n")

		fout.write("**.s" + str(key) + ".nClientHandlers = " + str(1) + "\n")
		fout.write("**.s" + str(key) + ".nDownloaders = " + str(options.surrogatesOut) + "\n")
		fout.write("**.s" + str(key) + ".type = \"s\"\n")
		fout.write("\n")

	#set up clients
	for key in bottleAttributes.clientIds:
		fout.write("**.c" + str(key) + ".cdn_RequestsAssignerReceiver.commandsScript = \"./dataset/" + str(key) + "\"\n")
		fout.write("**.c" + str(key) + ".staticContentExchange_ServicePeer.cacheType = \"LRU\"\n")
		if options.shrink is True:
			fout.write("**.c" + str(key) + ".staticContentExchange_ServicePeer.shrink = 1\n")
		else:
			fout.write("**.c" + str(key) + ".staticContentExchange_ServicePeer.shrink = 0\n")

		fout.write("**.c" + str(key) + ".staticContentExchange_ServicePeer.cacheContents = \"NULL\"\n")
		fout.write("**.c" + str(key) + ".staticContentExchange_ServicePeer.cacheSizeInMbs = \"0.0\"\n")

		fout.write("**.c" + str(key) + ".staticContentExchange_ServicePeer.objectsReference = \"./dataset/objects\"\n")
		fout.write("**.c" + str(key) + ".nServerHandlers = 0\n")

		fout.write("**.c" + str(key) + ".nClientHandlers = " + str(1) + "\n")
		fout.write("**.c" + str(key) + ".nDownloaders = " + str(options.clientsOut) + "\n")
		fout.write("**.c" + str(key) + ".type = \"c\"\n")

		fout.write("\n")


	#set up origins
	flag = 0	
	for key in bottleAttributes.originsIds:
		flag += 1
		fout.write("**.o" + str(key) + ".cdn_RequestsAssignerReceiver.commandsScript = \"NULL\"\n")
		fout.write("**.o" + str(key) + ".staticContentExchange_ServicePeer.cacheType = \"LRU\"\n")
		if options.shrink is True:
			fout.write("**.o" + str(key) + ".staticContentExchange_ServicePeer.shrink = 1\n")
		else:
			fout.write("**.o" + str(key) + ".staticContentExchange_ServicePeer.shrink = 0\n")
		fout.write("**.o" + str(key) + ".staticContentExchange_ServicePeer.cacheContents = \"./caches/originsContent"+str(flag)+"\"\n")
		fout.write("**.o" + str(key) + ".staticContentExchange_ServicePeer.cacheSizeInMbs = \"" + str(math.ceil(((bottleAttributes.totalWebSiteSize / 1024.0) / 1024.0))) + "\"\n")

		fout.write("**.o" + str(key) + ".staticContentExchange_ServicePeer.objectsReference = \"./dataset/objects\"\n")
		fout.write("**.o" + str(key) + ".nServerHandlers = " + str(options.originsIn) + "\n")

		fout.write("**.o" + str(key) + ".nClientHandlers = 0\n")
		fout.write("**.o" + str(key) + ".nDownloaders = 0\n")
		fout.write("**.o" + str(key) + ".type = \"o\"\n")
		fout.write("\n")

	#set up central unit
	fout.write("**.cdn_CentralUnit.policy = \"" + str(options.policy) + "\"")

	#set up stats
	fout.write("\n**.stats.statsFile = \"./stats/stats\"")
	fout.close()

	#set up origins 2
	try:
		fout = open(bottleAttributes.cachesPath + '/' + "originsContent", 'w')
	except:
		showSomeError(parent, "error while creating originsOptions.ini")
		return 1
	for objId in bottleAttributes.allObjectIds:
		fout.write(str(objId) + " s\n")
	fout.close()

def buildBottleRNP(parent, options):
	bottleAttributes.reset()
	if prepareBottle(parent, options):
		showSomeError(parent, "Bottle creation aborted")
		return
	if prepareStats(parent, options):
		showSomeError(parent, "Bottle creation aborted")
		os.system("rm -rf \"" + bottleAttributes.bottlePath + '\"')
		return
	random.seed(options.netSeed)
	if prepareNetwork(parent, options):
		showSomeError(parent, "Bottle creation aborted")
		os.system("rm -rf \"" + bottleAttributes.bottlePath + '\"')
		return
	random.seed(options.traceSeed)
	if prepareDataset(parent, options):
		showSomeError(parent, "Bottle creation aborted")
		os.system("rm -rf \"" + bottleAttributes.bottlePath + '\"')
		return
	if prepareCaches(parent, options):
		showSomeError(parent, "Bottle creation aborted")
		os.system("rm -rf \"" + bottleAttributes.bottlePath + '\"')
		return
	if prepareInis(parent, options):
		showSomeError(parent, "Bottle creation aborted")
		os.system("rm -rf \"" + bottleAttributes.bottlePath + '\"')
		return
	d = wx.MessageDialog(parent, "Bottle created successfully.", "All ok", wx.OK)
	d.ShowModal() # Shows it
	d.Destroy() # finally destroy it when finished.

def getBitrate(options, router1, router2):
	fileLink = open(options.currentPath+"routersLink")
	patObjectsFile = re.compile("(\d+)(\ +)(\d+)(\ +)(\d+)")
	for line in fileLink:
		if(line.find(str(router1)+" "+str(router2)) != -1):
			patRes = patObjectsFile.match(line)
	return patRes.group(5)

def getFiberLineName(options, router1, router2):
	fileLink = open(options.currentPath+"routersLink")
	patObjectsFile = re.compile("(\d+)(\ +)(\d+)(\ +)(\d+)")
	for line in fileLink:
		if(line.find(str(router1)+" "+str(router2)) != -1):
			if( int(patObjectsFile.match(line).group(5)) == 6000000):
				return "fiberline6M"
			if( int(patObjectsFile.match(line).group(5)) == 20000000):
				return "fiberline20M"
			if( int(patObjectsFile.match(line).group(5)) == 34000000):
				return "fiberline34M"
			if( int(patObjectsFile.match(line).group(5)) == 257000000):
				return "fiberline257M"
			if( int(patObjectsFile.match(line).group(5)) == 155000000):
				return "fiberline155M"
			if( int(patObjectsFile.match(line).group(5)) == 622000000):
				return "fiberline622M"
			if( int(patObjectsFile.match(line).group(5)) == 2500000000):
				return "fiberline2G"
			if( int(patObjectsFile.match(line).group(5)) == 10000000000):
				return "fiberline10G"

def getRouter(options, node, kind):
	if kind == "clients":
		fileLink = open(options.currentPath+"clientsLink")
	elif kind == "origins":
		fileLink = open(options.currentPath+"originsLink")
	elif kind == "surrogates":
		fileLink = open(options.currentPath+"surrogatesLink")
	count = 0
	for line in fileLink:
		if(count == node):
			return int(line)
		count += 1
