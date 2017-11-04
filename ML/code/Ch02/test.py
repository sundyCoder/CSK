
import matplotlib
from numpy import *
import matplotlib.pyplot as plt
import array
import kNN

datingDataMat, datingLabels = kNN.file2matrix('datingTestSet.txt')
#fig = plt.figure()
#ax = fig.add_subplot(111)
#ax.scatter(datingDataMat[:,1],datingDataMat[:,2],15.0*array(datingLabels), 15.0*array(datingLabels))
#plt.show()
#kNN.datingClassTest()
kNN.classifyPerson()




