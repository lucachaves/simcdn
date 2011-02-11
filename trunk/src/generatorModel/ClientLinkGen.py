import re
import random
import numpy as np


#Generate links by percentage of POP in networking
def clientPropor(clientSize, configModel, pop, numServer):
    # File hava percentage of link in POPs of the RNP
    client = open("./"+configModel+"/estadosLinkRNP")
    patObjectsFile = re.compile("(\d+\.\d+)(\ +)(\d+)(\ +)(\w+)")
    # File have links of the clients in routers
    fout = open("./"+configModel+"/clientsLink", 'w')
    # Generate links
    count = 0
    clients = []
    for line in client:
        patRes = patObjectsFile.match(line)
        percent = float(patRes.group(1))
        numPOPClient = round(clientSize*percent/100)
        for x in range(0, int(numPOPClient)):
            fout.write(str(count+numServer)+"\n")
            clients.append(count+numServer)
        count = count +1
    count = 0
    if len(clients) < clientSize:
        for x in range(0, clientSize - len(clients)):
            fout.write(str(count+numServer)+"\n")
            clients.append(count+numServer)
            count = count +1
            if(count == 2*pop+1):
                count = 0
    fout.close()
    
# Generate Client by Zipf        
def clientZipf(clientSize, configModel, pop, numServer):
    fout = open("./"+configModel+"/clientsLink", 'w')
    varaibles = np.random.zipf(2, clientSize)
    for value in varaibles:
        fout.write(str(value+numServer)+"\n")

# Generate Client by Uniforme
def clientUnifor(clientSize, configModel, pop, numServer):
    fout = open("./"+configModel+"/clientsLink", 'w')
    numClient = 0 
    while numClient < clientSize:
        fout.write(str((numClient%pop)+numServer)+"\n")
        numClient = numClient + 1

# Generate Client by Ramdon    
def clientRamd(clientSize, configModel, pop, numServer):
    fout = open("./"+configModel+"/clientsLink", 'w')
    for x in range(0, clientSize):
        fout.write(str(random.randint(0,pop)+numServer)+"\n")  