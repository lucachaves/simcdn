import os
import numpy

def generateContentInOrigen(numTotalServer, numTotalFile, bottleName, configModel):
    
    fileProject = "./"+configModel+"/bootle/"+bottleName
    fout = open(fileProject+"/dataset/objects","r")
    
    segmentsReference = []
    for line in fout:
        segmentsReference.append(line);
    fout.close()
    
    segFile = {}
    for numFile in range(0, numTotalFile):
        segFile[numFile] = []
        
    for line in segmentsReference:
        line = line.split()
        idSeg = line[0]
        idFile = line[-1]
        segFile[int(idFile)] += [idSeg]

    pages = {}
    for numFile in range(0, numTotalFile):
        pages[numFile] = []
        
    i = 0    
    for server in numpy.random.uniform(1, numTotalServer, numTotalFile):
        pages[i] = numpy.random.uniform(0, numTotalServer, int(server))
        i += 1
    #print pages
        
    pagesInServers ={}
    for numServer in range(0, numTotalServer):
        pagesInServers[numServer] = []
        
    #print pagesInServers
    for page, servers in pages.iteritems():
        for server in servers:
            pagesInServers[int(server)] += [page]
    #print pagesInServers
    for page, servers in pagesInServers.iteritems():
        pagesInServers[page] = sorted(list(set(servers)))
    #print pagesInServers
    for numServer in range(0,numTotalServer):
        filename = fileProject+"/caches/originsContent"+str(numServer+1) 
        existContent = ""
        if os.path.exists(filename):
            fr = open(filename, "r")
            existContent = fr.read()
            fr.close()
        fin = open(filename, "w")
        fin.write(existContent)
        for page in pagesInServers[numServer]:
            for seg in segFile[page]:
                fin.write(seg+' s\n')
        fin.close()

#modifyContent("exp01", 27, 27, "configModel")