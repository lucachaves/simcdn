import os
import numpy

def modifyContent(bottleName, servers, numFile, configModel):
    fileProject = "./"+configModel+"/bootle/"+bottleName
    fout = open(fileProject+"/dataset/objects","r")
    segmentsReference = []
    for line in fout:
        segmentsReference.append(line);
    fout.close()
    segFile = {}
    for x in range(0, numFile):
        segFile[x] = []
    #print segFile
    for seg in segmentsReference:
        x = seg.split()
        value = x[0]
        key = x[-1]
        segFile[int(key)] += [value]
    #print segFile
    pages = {}
    for x in range(0, numFile):
        pages[x] = []
    i = 0    
    for server in numpy.random.uniform(1, servers, numFile):
        pages[i] = numpy.random.uniform(0, servers, int(server))
        i = i + 1
    #print pages
        
    pagesInServers ={}
    for x in range(0, servers):
        pagesInServers[x] = []
    #print pagesInServers
    for page, servs in pages.iteritems():
        for serv in servs:
            pagesInServers[int(serv)] += [page]
    #print pagesInServers
    for page, servs in pagesInServers.iteritems():
        pagesInServers[page] = sorted(list(set(servs)))
    #print pagesInServers
    for serve in range(0,servers):
        filename = fileProject+"/caches/originsContent"+str(serve+1) 
        existContent = ""
        if os.path.exists(filename):
            fr = open(filename, "r")
            existContent = fr.read()
            fr.close()
        fin = open(filename, "w")
        fin.write(existContent)
        for page in pagesInServers[serve]:
            for seg in segFile[page]:
                fin.write(seg+' s\n')
        fin.close()

#modifyContent("exp01", 27, 27, "configModel")