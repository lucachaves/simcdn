import numpy

def generatePage(numTotalFile, repGenModel, sizeSeg, bitrate, timeFilePareto):
    #bitrate
    fout = open("./"+repGenModel+"/website", 'w')
    
    timesFile = numpy.random.pareto(3., numTotalFile) + 5. #time in minute (avg 5m)
    #print timesFile #time
    sizesFile = timesFile*60*bitrate #size (x60 convert to second)
    #print sizesFile #size
    
    content = ""
    numSeg = 0
    for numFile in range(0, numTotalFile):
        for flag in range(0, int(sizesFile[numFile]/sizeSeg)):
            content += str(numSeg)+" "+str(sizeSeg)+" "+str(numFile)+"\n"
            numSeg += 1
        if (sizesFile[numFile])%sizeSeg != 0:
            content += str(numSeg)+" "+str((sizesFile[numFile])%sizeSeg)+" "+str(numFile)+"\n"
            numSeg += 1
    
    
    fout.write(content)
    fout.close()
    
    return numSeg