import numpy
import random

def generateTraffic(numClient, numTraffic, numTotalFile, configModel, bottleName, gapFileExponetial, absSizeSeg, bitrate):
    fout = open("./"+configModel+"/traffic", 'w')
    
    #obter os segmentos de um arquivo
    fileProject = "./"+configModel
    fin = open(fileProject+"/website","r")
    
    segFileReference = []
    for line in fin:
        segFileReference.append(line);
    fin.close()
    
    idSegFile = {}
    sizeSegFile = {}
    for numFile in range(0, numTotalFile):
        idSegFile[numFile] = []
        sizeSegFile[numFile] = []

    for line in segFileReference:
        lineFile = line.split()
        idSeg = lineFile[0]
        idFile = lineFile[-1]
        sizeSeg = lineFile[1]
        idSegFile[int(idFile)] += [idSeg]
        sizeSegFile[int(idFile)] += [sizeSeg]
    
    fileTotalSize = {}
    for numFile in range(0, numTotalFile):
        fileTotalSize[numFile] = []
        
    for idFile, sizesSeg in sizeSegFile.iteritems():
        size = 0.0
        for sizeSeg in sizesSeg:
            size += float(sizeSeg)
        fileTotalSize[idFile] = size
        
    #intervalo entre arquivos
    gapFile = numpy.random.exponential(gapFileExponetial, numTraffic) #time
    #lista de arquivos
    popularityFile = numpy.random.uniform(0, numTotalFile, numTraffic) #id file
    #sortear o inicio do video baseado em seu tamanho
    startFile = range(numTraffic)
    for numFile in range(0,numTraffic):
        lim = fileTotalSize[int(popularityFile[numFile])]
        startFile[numFile] = numpy.random.uniform(0, lim , 1)[0] #pareto(1, numTraffic) - 1 sizeSeg
    #laco por cada arquivo para sortear o permanenci do video baseado no restante do seu tamanho
    permanenceFile = range(numTraffic)
    for numFile in range(0,numTraffic):
        lim = fileTotalSize[int(popularityFile[numFile])]
        permanenceFile[numFile] = numpy.random.uniform(startFile[numFile], lim, 1)[0] #sizeSeg
    #distribuicao do cliente
    distClient = numpy.random.uniform(0, numClient, numTraffic) #ID client
    
    content = ""
    traffic = {}
    for idSeg in range(0, numTraffic):
        #print str(idSeg)+"-"+str(gaps[idSeg])+" "+str(clients[idSeg])+" "+str(pages[idSeg])+"\n"
        numSeg = int(permanenceFile[idSeg]/absSizeSeg) - int(startFile[idSeg]/absSizeSeg)
        gapSeg = 0 #time (sera necessario)
        for numFile in range(int(startFile[idSeg]/absSizeSeg), int(permanenceFile[idSeg]/absSizeSeg)):
            traffic[gapFile[idSeg]+gapSeg] = str(int(distClient[idSeg]))+" "+str(idSegFile[int(popularityFile[idSeg])][numFile])+"\n"
            #content += str(gapFile[idSeg]+gapSeg)+" "+str(int(distClient[idSeg]))+" "+str(idSegFile[int(popularityFile[idSeg])][numFile])+"\n"
            gapSeg = gapSeg + absSizeSeg/bitrate
            #print int(startFile[idSeg]/absSizeSeg)
            #print idSegFile[int(popularityFile[idSeg])][int(startFile[idSeg]/absSizeSeg)]
            #print int(permanenceFile[idSeg]/absSizeSeg)
            #print idSegFile[int(popularityFile[idSeg])][int(permanenceFile[idSeg]/absSizeSeg)]
    #print traffic
    keySorted = sorted(traffic)
    for numFile in keySorted:
        content += str(numFile)+" "+str(traffic[numFile])
    #print content
    fout.write(content)
    fout.close()