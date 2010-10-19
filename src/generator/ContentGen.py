'''
Created on Aug 25, 2010

@author: lucachaves
'''
import os

def modifyContent(bottleName, servers, numFile):
    fileProject = "./RNP/bootle/"+bottleName
    fout = open(fileProject+"/dataset/objects","r")
    segmentsReference = []
    for line in fout:
        segmentsReference.append(line);
    fout.close()
    i = 0
    segmentsReferenceFile = []
    for seg in segmentsReference:
        segmentsReferenceFile.append(seg[:-1]+' '+str(i)+'\n')
        i += 1
        if i == numFile:
            i = 0
    fout = open(fileProject+"/dataset/objects","w")
    for seg in segmentsReferenceFile:
        fout.write(seg)
    fout.close()
    
    segFile = {}
    for x in range(0, numFile):
        segFile[x] = []
    #print segFile
    for seg in segmentsReferenceFile:
        x = seg.split()
        value = x[0]
        key = x[-1]
        segFile[int(key)] += [value]
    #print segFile
    i = 1
    for x in range(0,numFile):
        filename = fileProject+"/caches/originsContent"+str(i) 
        existContent = ""
        if os.path.exists(filename):
            fr = open(filename, "r")
            existContent = fr.read()
            fr.close()
        fin = open(filename, "w")
        fin.write(existContent)
        for seg in segFile[x]:
            fin.write(seg+' s\n')
        fin.close()
        i += 1
        if i == servers +1:
            i = 1

#modifyContent("exp11", 27, 500)
