import numpy as np

def webSite(numFile, configModel, sizeSeg):
    fout = open("./"+configModel+"/website", 'w')
    a, m = 3., 5.
    variables = np.random.pareto(a, numFile) + m
    content = ""
    numSeg = 0
    for value in range(0, numFile):
        for flag in range(0, int(variables[value]*1000/sizeSeg)):
            content += str(numSeg)+" "+str(sizeSeg)+" "+str(value)+"\n"
            numSeg = numSeg + 1
        if (variables[value]*1000)%sizeSeg != 0:
            content += str(numSeg)+" "+str((variables[value]*1000)%sizeSeg)+" "+str(value)+"\n"
            numSeg = numSeg + 1
    fout.write(content)
    fout.close()
    return numSeg