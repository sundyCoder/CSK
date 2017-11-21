import regTrees
import numpy as np

testMat = np.mat(np.eye(4))
mat0,mat1 = regTrees.binSplitDataSet(testMat, 1, 0.5)
#print(mat0)
print(mat1)
#print(testMat)