# 2. Caffe Tutorial 2

## 1. Solver 求解器
#### 1.1 Caffe中有以下求解器:

1. Stochastic Gradient Descent (type: "SGD"),
1. AdaDelta (type: "AdaDelta"),
1. Adaptive Gradient (type: "AdaGrad"),
1. Adam (type: "Adam"),
1. Nesterov’s Accelerated Gradient (type: "Nesterov") and
1. RMSprop (type: "RMSProp")

#### 1.2 The Solver

1. scaffolds the optimization bookkeeping and creates the training network for learning and test network(s) for evaluation.
1. iteratively optimizes by calling forward / backward and updating parameters
1. (periodically) evaluates the test networks
1. snapshots the model and solver state throughout the optimizatio

#### 1.3 每一个iteration做了如下工作

1. calls network forward to compute the output and loss
1. calls network backward to compute the gradients
1. incorporates the gradients into parameter updates according to the solver method
1. updates the solver state according to learning rate, history, and method
1. to take the weights all the way from initialization to learned mod



一个epoch即对所有训练数据的一轮遍历


#### Reference

[http://caffe.berkeleyvision.org/tutorial/solver.html](http://caffe.berkeleyvision.org/tutorial/solver.html)