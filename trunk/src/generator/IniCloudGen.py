'''
Created on Sep 20, 2010

@author: lucachaves
'''
import random

nSwitch = 10
maxHost = 50
nHost = 100
nRouter = 56 
hosts = []
routers = []
for x in range(0,nSwitch):
    hosts.insert(x, 0)
    routers.insert(x,random.randint(27,53))
print(hosts)
for num in range(nRouter+1, nRouter + nHost+1): 
    switch = random.randint(0, nSwitch - 1)
    print("**.m"+str(switch)+".host["+str(hosts[switch])+"].cdn_RequestsAssignerReceiver.commandsScript = \"./dataset/"+str(num)+"\"")
    hosts[switch] += 1
print(hosts)
print("\n\n\n")
for x in range(0,nSwitch):
    print("m"+str(x)+": MediumLAN {")
    print("    parameters:")
    print("        n = "+str(hosts[x])+";")
    print("}")
print("\n\n\n")
for x in range(0,nSwitch):
    #print("for i=0.."+str(hosts[x])+"-1 {")
    print("r"+str(routers[x])+".ethg++ <--> m"+str(x)+".ethg;")
    #print("}")