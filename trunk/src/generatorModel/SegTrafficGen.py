import numpy
import random

def gapPoisson(numClient, numTraffic, numFile, configModel, bottleName, gamaDistribution, sizeSeg):
    fout = open("./"+configModel+"/traffic", 'w')
    
    #obter os segmentos de um arquivo
    fileProject = "./"+configModel#+"/bootle/"+bottleName
    fin = open(fileProject+"/website","r")
    segmentsReference = []
    for line in fin:
        segmentsReference.append(line);
    fin.close()
    segFile = {}
    segFileSize = {}
    for x in range(0, numFile):
        segFile[x] = []
        segFileSize[x] = []
    #print segFile
    for seg in segmentsReference:
        x = seg.split()
        value = x[0]
        key = x[-1]
        size = x[1]
        segFile[int(key)] += [value]
        segFileSize[int(key)] += [size]
    
    fileSize = {}
    for x in range(0, numFile):
        fileSize[x] = []
    for num, file in segFileSize.iteritems():
        size = 0.0
        for s in file:
            size = size + float(s)
            #print size
            fileSize[num] = size
        
    #intervalo entre arquivos
    gapFile = numpy.random.exponential(gamaDistribution, numTraffic) #time
    #popularidade
    popularityFile = numpy.random.uniform(0, numFile, numTraffic) #id file
    #laco por cada arquivo para sortear o inicio do video baseado em seu tamanho
    startFile = range(numTraffic)
    for x in range(0,numTraffic):
        lim = fileSize[int(popularityFile[x])]
        startFile[x] = numpy.random.uniform(0, lim , 1)[0] #pareto(1, numTraffic) - 1 size
    #laco por cada arquivo para sortear o permanenci do video baseado no restante do seu tamanho
    permanenceFile = range(numTraffic)
    for x in range(0,numTraffic):
        lim = fileSize[int(popularityFile[x])]
        permanenceFile[x] = numpy.random.uniform(startFile[x], lim, 1)[0] #size
    #distribuicao do cliente
    distClient = numpy.random.uniform(0, numClient, numTraffic) #ID client
    
    content = ""
    traffic = {}
    for value in range(0, numTraffic):
        #print str(value)+"-"+str(gaps[value])+" "+str(clients[value])+" "+str(pages[value])+"\n"
        numSeg = int(permanenceFile[value]/sizeSeg) - int(startFile[value]/sizeSeg)
        gapSeg = 0 #time (sera necessario)
        for x in range(int(startFile[value]/sizeSeg), int(permanenceFile[value]/sizeSeg)):
            traffic[gapFile[value]+gapSeg] = str(int(distClient[value]))+" "+str(segFile[int(popularityFile[value])][x])+"\n"
            #content += str(gapFile[value]+gapSeg)+" "+str(int(distClient[value]))+" "+str(segFile[int(popularityFile[value])][x])+"\n"
            gapSeg = gapSeg + 0.5
            #print int(startFile[value]/sizeSeg)
            #print segFile[int(popularityFile[value])][int(startFile[value]/sizeSeg)]
            #print int(permanenceFile[value]/sizeSeg)
            #print segFile[int(popularityFile[value])][int(permanenceFile[value]/sizeSeg)]
    #print traffic
    keySorted = sorted(traffic)
    for x in keySorted:
        content += str(x)+" "+str(traffic[x])
    #print content
    fout.write(content)
    fout.close()