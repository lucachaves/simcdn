'''
Created on Jul 7, 2010

@author: lucachaves
'''
import wx
import sys
import os
import WebsiteGen
import ClientGen
import TrafficGen
import ContentGen
from os.path import dirname
from BottleBuilderRNP import buildBottle


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



class MyApp(wx.App):
    def OnInit(self):
        options = OptionsTeste()

        cdnsimInstallationDir = dirname(dirname(sys.path[0]))
        options.currentPath = "./RNP/"
        
        options.outputDir = options.currentPath+"bootle"
        options.bottleName = bottleName
        options.package = "models."+options.bottleName
        
        options.placement = options.currentPath+"placement"
        options.placementDir =  options.currentPath 
        options.shrink = False
        
        options.traffic = options.currentPath+"traffic"
        options.objects = options.currentPath+"website"
         
        options.linkSpeed = 1000
        options.routersGraphFile = options.currentPath+"routers" 
        options.clients = numClient
        options.surrogates = 27 
        options.origins = 27
        
        options.clientsOut = 1000 
        options.surrogatesOut = 1000
        options.surrogatesIn = 1000
        options.originsIn = 1000
        options.nRetries = 3
        options.mean = 5
        
        options.policy = "0"
        
        
        buildBottle(None, options)
        
        return True

#cache size
bottleName = "exp02"
numClient = 100
kindDistr = "zipf" #zipf, uniforme
#mudar para tamanhos fixos (blocos)
numTraffic = 1000
numSeg = 1000
numFile = 500

os.system("rm -rf \"./RNP/bootle/"+bottleName+"\"")
print "Generate Client"
ClientGen.clientPropor(numClient)
print "Generate Website"
WebsiteGen.webSite(numSeg)
print "Generate Traffic"
TrafficGen.gapPoisson(numClient, numTraffic, numSeg)
print "Generate Bootle"
app = MyApp(0)
app.MainLoop()
print "Modify Content"
ContentGen.modifyContent(bottleName, 27, numFile)
print "Modify ned for RNP"
fr = open("./RNP/bootle/"+bottleName+"/base.ned", "r")
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
fout = open("./RNP/bootle/"+bottleName+"/base.ned", "w")
fout.write(temp.replace(temp[temp.find("r0: Router"):temp.find("c57: GenericHost")], newContent))
fout.close()
print "Copy Bootle to Models"
os.system("cp -r \"./RNP/bootle/"+bottleName+"\" \"../../models/"+bottleName+"\"")
os.system("rm -rf \"./RNP/bootle/"+bottleName+"\"")
print "Finished!"



