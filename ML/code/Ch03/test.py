from numpy import *
import trees
import treePlotter
#dataSet,dataLabel = trees.createDataSet()
#data1 = [[1,'no'],[1,'no']]
#ep = trees.calcShannonEnt(data1)
#print(ep)
#retEp = trees.chooseBestFeatureToSplit(dataSet)
#print(retEp)

#myTree = trees.createTree(dataSet,dataLabel)
#print(myTree)
#myTree=treePlotter.retrieveTree (0)
#trees.storeTree(myTree,'classifierStorage.txt')
#trees.grabTree('classifierStorage.txt')


fr = open('lenses.txt')
lenses = [inst.strip().split('\t') for inst in fr.readlines()]
print(lenses)
lensesLabels = ['age','prescript','astigmatic','tearRate']
lensesTree = trees.createTree(lenses,lensesLabels)
treePlotter.createPlot(lensesTree)



