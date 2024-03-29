import wx
import sys
import os
import SegWebsiteGen
import ClientLinkGen
import SegTrafficGen
import OrigenContentGen
from os.path import dirname
from BottleBuilderRNP import buildBottleRNP



def modifyNeed(repGenModel, bottleName):
    fr = open("./" + repGenModel + "/bootle/" + bottleName + "/base.ned", "r")
    temp = fr.read()
    fr.close()
    newContent = """
        r0: Router {
            parameters:
                @display("i=abstract/router;p=202,231");
        }
        r1: Router {
            parameters:
                @display("i=abstract/router;p=526,596");
        }
        r2: Router {
            parameters:
                @display("i=abstract/router;p=257,565");
        }
        r3: Router {
            parameters:
                @display("i=abstract/router;p=318,517");
        }
        r4: Router {
            parameters:
                @display("i=abstract/router;p=929,636");
        }
        r5: Router {
            parameters:
                @display("i=abstract/router;p=929,188");
        }
        r6: Router {
            parameters:
                @display("i=abstract/router;p=347,188");
        }
        r7: Router {
            parameters:
                @display("i=abstract/router;p=573,540");
        }
        r8: Router {
            parameters:
                @display("i=abstract/router;p=241,293");
        }
        r9: Router {
            parameters:
                @display("i=abstract/router;p=630,496");
        }
        r10: Router {
            parameters:
                @display("i=abstract/router;p=300,334");
        }
        r11: Router {
            parameters:
                @display("i=abstract/router;p=389,334");
        }
        r12: Router {
            parameters:
                @display("i=abstract/router;p=659,188");
        }
        r13: Router {
            parameters:
                @display("i=abstract/router;p=698,496");
        }
        r14: Router {
            parameters:
                @display("i=abstract/router;p=860,447");
        }
        r15: Router {
            parameters:
                @display("i=abstract/router;p=93,636");
        }
        r16: Router {
            parameters:
                @display("i=abstract/router;p=929,422");
        }
        r17: Router {
            parameters:
                @display("i=abstract/router;p=750,540");
        }
        r18: Router {
            parameters:
                @display("i=abstract/router;p=422,548");
        }
        r19: Router {
            parameters:
                @display("i=abstract/router;p=454,293");
        }
        r20: Router {
            parameters:
                @display("i=abstract/router;p=659,636");
        }
        r21: Router {
            parameters:
                @display("i=abstract/router;p=860,384");
        }
        r22: Router {
            parameters:
                @display("i=abstract/router;p=93,188");
        }
        r23: Router {
            parameters:
                @display("i=abstract/router;p=93,486");
        }
        r24: Router {
            parameters:
                @display("i=abstract/router;p=347,636");
        }
        r25: Router {
            parameters:
                @display("i=abstract/router;p=781,596");
        }
        r26: Router {
            parameters:
                @display("i=abstract/router;p=487,225");
        }
        r27: Router {
            parameters:
                @display("i=abstract/router;p=202,941");
        }
        r28: Router {
            parameters:
                @display("i=abstract/router;p=558,1211");
        }
        r29: Router {
            parameters:
                @display("i=abstract/router;p=270,1279");
        }
        r30: Router {
            parameters:
                @display("i=abstract/router;p=309,1219");
        }
        r31: Router {
            parameters:
                @display("i=abstract/router;p=929,1316");
        }
        r32: Router {
            parameters:
                @display("i=abstract/router;p=929,899");
        }
        r33: Router {
            parameters:
                @display("i=abstract/router;p=346,899");
        }
        r34: Router {
            parameters:
                @display("i=abstract/router;p=526,1279");
        }
        r35: Router {
            parameters:
                @display("i=abstract/router;p=241,984");
        }
        r36: Router {
            parameters:
                @display("i=abstract/router;p=620,1165");
        }
        r37: Router {
            parameters:
                @display("i=abstract/router;p=309,1040");
        }
        r38: Router {
            parameters:
                @display("i=abstract/router;p=391,1034");
        }
        r39: Router {
            parameters:
                @display("i=abstract/router;p=659,899");
        }
        r40: Router {
            parameters:
                @display("i=abstract/router;p=705,1165");
        }
        r41: Router {
            parameters:
                @display("i=abstract/router;p=848,1149");
        }
        r42: Router {
            parameters:
                @display("i=abstract/router;p=93,1316");
        }
        r43: Router {
            parameters:
                @display("i=abstract/router;p=929,1099");
        }
        r44: Router {
            parameters:
                @display("i=abstract/router;p=758,1211");
        }
        r45: Router {
            parameters:
                @display("i=abstract/router;p=415,1235");
        }
        r46: Router {
            parameters:
                @display("i=abstract/router;p=454,984");
        }
        r47: Router {
            parameters:
                @display("i=abstract/router;p=659,1316");
        }
        r48: Router {
            parameters:
                @display("i=abstract/router;p=848,1053");
        }
        r49: Router {
            parameters:
                @display("i=abstract/router;p=93,899");
        }
        r50: Router {
            parameters:
                @display("i=abstract/router;p=93,1099");
        }
        r51: Router {
            parameters:
                @display("i=abstract/router;p=357,1316");
        }
        r52: Router {
            parameters:
                @display("i=abstract/router;p=797,1279");
        }
        r53: Router {
            parameters:
                @display("i=abstract/router;p=510,941");
        }
        r54: Router {
            parameters:
                @display("i=abstract/router;p=346,764");
        }
        r55: Router {
            parameters:
                @display("i=abstract/router;p=449,795");
        }
        r56: Router {
            parameters:
                @display("i=abstract/router;p=347,826");
        }
        """
    fout = open("./" + repGenModel + "/bootle/" + bottleName + "/base.ned", "w")
    fout.write(temp.replace(temp[temp.find("r0: Router"):temp.find("c57: GenericHost")], newContent))
    fout.close()

class OptionsTeste:
    currentPath = None
    policy = None

    routersGraphFile = None
    clients = None
    surrogates = None
    origins = None
    linkSpeed = None

    clientsOut = None
    surrogatesOut = None
    surrogatesIn = None
    originsIn = None

    traffic = None
    objects = None

    placement = None
    placementDir = None

    outputDir = None
    cdnsimDir = None
    bottleName = None
    inetDir = None
    omnetppDir = None

    nRetries = None
    mean = None

    shrink = None
    netSeed = 0
    traceSeed = 0
    
    package = None
    
    cacheType = None
    cacheSize = 0



class MyApp(wx.App):
    def OnInit(self):
        options = OptionsTeste()

        cdnsimInstallationDir = dirname(dirname(sys.path[0]))
        options.currentPath = "./"+repGenModel+"/"
        
        options.outputDir = options.currentPath+"bootle"
        options.bottleName = bottleName
        options.package = "models."+options.bottleName
        
        options.placement = options.currentPath+"placement"
        options.placementDir =  options.currentPath 
        options.shrink = False
        
        options.traffic = options.currentPath+"traffic"
        options.objects = options.currentPath+"website"
         
        options.linkSpeed = 1000
        options.routersGraphFile = options.currentPath+"/routersLink" 
        options.clients = numTotalClient
        options.surrogates = 27 
        options.origins = numTotalServer
        
        options.clientsOut = 1000 
        options.surrogatesOut = 1000
        options.surrogatesIn = 1000
        options.originsIn = 1000
        options.nRetries = 3
        options.mean = 5
        
        options.policy = selectionServer
        
        options.cacheSize = cacheSize
        options.cacheType = cacheKind
              
        buildBottleRNP(None, options)
        
        return True
    
'''Parameters'''
pop = 27
numTotalServer = 27
repGenModel = "configModel"
bottleName = "exp01"
numSeg = 0
sizeSeg = 5000

''' Factor and Level '''
numTotalClient = 10**2 #10^1, 10^2, 10^3, 10^4, 10^5 (ClientLinkGen)
#falta param Dist para ZIPF
clientDistr = "uniforme" #zipf, uniforme, pro (ClientLinkGen)
numTraffic = 10**4 #10^3, 10^4, 10^5 (SegTrafficGen)
gapFileExponetial = 30 #The scale parameter of Exponential distribuition with values 30s, 60s exponetial (SegTrafficGen)
# se for uniforme nao precisa desses valores
permanence = "uniforme" #10%, 25%, 50%, 100% uniforme (fixo SegTrafficGen)
# definir
start = "pareto" #pareto (fixo SegTrafficGen)
# definir
popularity = "zipf" #zipf (fixo SegTrafficGen)
# definir
location = "propor" #propor (fixo OrigenContenGen) 
cacheSize = 10**7 #10^7, 10^9, infinito tamanho em byte (BottleBuilderRNP)
cacheKind = "LRU" #LRU, LFU (BottleBuilderRNP)
selectionServer = "0" #NFC - 0, NMC, NMCL, Balanced, RSC, Random (FALTA COLOCAR O PARAMETRO)
numTotalFile = 10**3 #10^3, 10^4, 10^5 (SegWebsiteGen)
timeFilePareto = 3. #shape of the Pareto distribution (SegWebsiteGen)
bitrate = 128 #128, 256, 1024 (SegWebsiteGen)
sizeFile = 0 #Calculado no SegWebsiteGem pelo timeFile e bitrate (SegWebsiteGen)

'''Generator Script'''
os.system("rm -rf \"../../models/"+bottleName+"\"")
print "Generate Client Link"
ClientLinkGen.generateLinks(clientDistr, numTotalClient, repGenModel, pop, numTotalServer)
print "Generate Website"
numSeg = SegWebsiteGen.generatePage(numTotalFile, repGenModel, sizeSeg, bitrate, timeFilePareto)
#print "Num of Seg " + str(numSeg)
print "Generate Traffic"
SegTrafficGen.generateTraffic(numTotalClient, numTraffic, numTotalFile, repGenModel, bottleName, gapFileExponetial, sizeSeg, bitrate)
print "Generate Bootle"
app = MyApp(0)
app.MainLoop()
print "Modify Content"
OrigenContentGen.generateContentInOrigen(numTotalServer, numTotalFile, bottleName, repGenModel)
print "Modify need for RNP"
modifyNeed(repGenModel, bottleName)
print "Copy Bootle to Models"
os.system("cp -r \"./"+repGenModel+"/bootle/"+bottleName+"\" \"../../models/"+bottleName+"\"")
os.system("rm -rf \"./"+repGenModel+"/bootle/"+bottleName+"\"")
print "Finished!"



