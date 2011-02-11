import os

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

#modifyContent("exp01", 27, 27, "configModel")
