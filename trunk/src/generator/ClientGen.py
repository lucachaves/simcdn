'''
Created on Aug 17, 2010

@author: lucachaves
'''
import re
import random
import numpy as np

client = open("./estados/estados3")
fout = open("./RNP/clientsLink", 'w')
patObjectsFile = re.compile("(\d+\.\d+)(\ +)(\d+)(\ +)(\w+)")


def clientPropor(sizeNet):
    count = 0
    clients = []
    for line in client:
        patRes = patObjectsFile.match(line)
        percent = float(patRes.group(1))
        total = round(sizeNet*percent/100)
        for x in range(0, int(total)):
            fout.write(str(count+27)+"\n")
            clients.append(count+27)
        count = count +1
    count = 0
    if len(clients) < sizeNet:
        for x in range(0, sizeNet - len(clients)):
            fout.write(str(count+27)+"\n")
            clients.append(count+27)
            count = count +1
            if(count == 2*27+1):
                count = 0
    fout.close()
    return clients
        
def clientZipf(sizeNet):
    varaibles = np.random.zipf(2, 1000)
    for value in varaibles:
        fout.write(str(value)+"\n")

def clientUnifor(sizeNet):
    count = 0
    for y in range(0, 27):
        for x in range(0, int(sizeNet/27)):
            fout.write(str(count)+"\n")            
        count = count +1
    if sizeNet%27 != 0:
        for x in range(0, int(sizeNet%27)):
            fout.write("24\n")
    
def clientRamd(sizeNet):
    for x in range(0, sizeNet):
        fout.write(str(random.randint(0,27))+"\n")  
        
