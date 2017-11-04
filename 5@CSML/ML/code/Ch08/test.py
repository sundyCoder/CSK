import regression

#xArr,yArr=regression.loadDataSet('ex0.txt')
#regValue = regression.lwlr(xArr[0],xArr,yArr,1.0)
#print(regValue)
#regression.lwlr(xArr[0],xArr,yArr,0.001)

xArr,yArr=regression.loadDataSet('abalone.txt')
regression.stageWise(xArr,yArr,0.01,200)
