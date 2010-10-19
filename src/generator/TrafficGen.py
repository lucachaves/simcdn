'''
Created on Aug 25, 2010

@author: lucachaves
'''
import numpy as np
import random



fout = open("./RNP/traffic", 'w')

def gapPoisson(client, sizeTraffic, webPage):
    #mudar gaps para exponecial
    variables = np.random.poisson(500, sizeTraffic)
    gaps = []
    gaps.append(0)
    for flag in range(0, sizeTraffic-1):
        gaps.append(gaps[flag] + variables[flag]/float(sizeTraffic*100))
    clients = np.random.zipf(2, sizeTraffic)
    for val in range(0,sizeTraffic-1):
        if clients[val] > client:
            clients[val] = random.randint(0, client-1)
    pages = np.random.zipf(2, sizeTraffic)
    for val in range(0,len(pages)-1):
        if pages[val] > webPage:
            pages[val] = random.randint(0, webPage-1)
    content = ""
    for value in range(0, sizeTraffic):
        #print str(value)+"-"+str(gaps[value])+" "+str(clients[value])+" "+str(pages[value])+"\n"
        content += str(gaps[value])+" "+str(clients[value])+" "+str(pages[value])+"\n"
    #print content
    fout.write(content)
    fout.close()
        