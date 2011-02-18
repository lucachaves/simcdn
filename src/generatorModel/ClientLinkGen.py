import re
import random
import numpy


def generateLink(kind, clientSize, configModel, pop, numServer):
    if cmp(kind, "zipf") == 0:
        #clientZipf(clientSize, configModel, pop, numServer)
        clientPropor(clientSize, configModel, pop, numServer)
    if cmp(kind, "uniforme") == 0:
        clientUnifor(clientSize, configModel, pop, numServer)

#Generate links by percentage of POP in networking
def clientPropor(clientSize, configModel, pop, numServer):
    # File have percentage of link in POPs of the RNP
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
    varaibles = numpy.random.zipf(2, clientSize)
    for value in varaibles:
        fout.write(str(value+numServer)+"\n")

# Generate Client by Uniforme
def clientUnifor(clientSize, configModel, pop, numServer):
    fout = open("./"+configModel+"/clientsLink", 'w')
    links = numpy.random.uniform(0, pop, clientSize)+numServer
    for link in links:
        fout.write(str(link)+"\n")

# Generate Client by Ramdon    
def clientRamd(clientSize, configModel, pop, numServer):
    fout = open("./"+configModel+"/clientsLink", 'w')
    for x in range(0, clientSize):
        fout.write(str(random.randint(0,pop)+numServer)+"\n")  