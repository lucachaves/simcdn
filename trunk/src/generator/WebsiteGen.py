'''
Created on Aug 25, 2010

@author: lucachaves
'''
import numpy as np

fout = open("./RNP/website", 'w')

def webSite(size):
    a, m = 3., 5.
    variables = np.random.pareto(a, size) + m
    content = ""
    for value in range(0, size):
        content += str(value)+" "+str(variables[value])+"\n"
    #print content
    fout.write(content)
    fout.close()
    return variables

#webSite(1000)