# Caffe Tutorial 3
## 3. xxx_solver.prototxt文件的解析

### 3.1 基本参数解析	
	# The train/test net protocol buffer definition
	train_net: "mnist/lenet_auto_train.prototxt"  #训练网络结构文件
	test_net: "mnist/lenet_auto_test.prototxt"    #验证用网络结构文件
	# test_iter specifies how many forward passes the test should carry out.
	# In the case of MNIST, we have test batch size 100 and 100 test iterations,
	# covering the full 10,000 testing images.
	test_iter: 100         #总的验证次数
	# Carry out testing every 500 training iterations.
	test_interval: 500     # 每训练500次测试一次
	# The base learning rate, momentum and the weight decay of the network.
	base_lr: 0.01           # 基本学习率
	momentum: 0.9           # 动量
	weight_decay: 0.0005    # 权重
	# The learning rate policy
	lr_policy: "inv"        # 学习率调整方法
	gamma: 0.0001    
	power: 0.75
	# Display every 100 iterations
	display: 100           # 每100次迭代显示一次
	# The maximum number of iterations
	max_iter: 10000        # 最大迭代次数
	# snapshot intermediate results
	snapshot: 5000         # 隔多少次迭代存储一次快照
	snapshot_prefix: "mnist/lenet"  #存储快照的目录

### 3.2 基本概念

Parameters

#### base_lr
	
	This parameter indicates the base (beginning) learning rate of the network. The value is a real number (floating point).
	
#### lr_policy
	
	This parameter indicates how the learning rate should change over time. This value is a quoted string.
	
	Options include:
	
	"step" - drop the learning rate in step sizes indicated by the gamma parameter.
	"multistep" - drop the learning rate in step size indicated by the gamma at each specified stepvalue.
	"fixed" - the learning rate does not change.
	"exp" - gamma^iteration
	"poly" -
	"sigmoid" -
#### gamma	

	This parameter indicates how much the learning rate should change every time we reach the next "step." The value is a real number, and can be thought of as multiplying the current learning rate by said number to gain a new learning rate.
	
####  stepsize
	
	This parameter indicates how often (at some iteration count) that we should move onto the next "step" of training. This value is a positive integer.
	
#### stepvalue
	
	This parameter indicates one of potentially many iteration counts that we should move onto the next "step" of training. This value is a positive integer. There are often more than one of these parameters present, each one indicated the next step iteration.
	
#### max_iter
	
	This parameter indicates when the network should stop training. The value is an integer indicate which iteration should be the last.
	
#### momentum
	
	This parameter indicates how much of the previous weight will be retained in the new calculation. This value is a real fraction.
	
#### weight_decay
	
	This parameter indicates the factor of (regularization) penalization of large weights. This value is a often a real fraction.
	
#### solver_mode
	
	This parameter indicates which mode will be used in solving the network.
	
	Options include:
	
	CPU
	GPU
#### snapshot
	
	This parameter indicates how often caffe should output a model and solverstate. This value is a positive integer.
	
#### snapshot_prefix:
	
	This parameter indicates how a snapshot output's model and solverstate's name should be prefixed. This value is a double quoted string.
	
#### net:
	
	This parameter indicates the location of the network to be trained (path to prototxt). This value is a double quoted string.

#### test_iter
	
	This parameter indicates how many test iterations should occur per test_interval. This value is a positive integer.
	
#### test_interval
	
	This parameter indicates how often the test phase of the network will be executed.
	
#### display
	
	This parameter indicates how often caffe should output results to the screen. This value is a positive integer and specifies an iteration count.
	
#### type
	
	This parameter indicates the back propagation algorithm used to train the network. This value is a quoted string.
	
	Options include:
	
	Stochastic Gradient Descent "SGD"
	AdaDelta "AdaDelta"
	Adaptive Gradient "AdaGrad"
	Adam "Adam"
	Nesterov’s Accelerated Gradient "Nesterov"
	RMSprop "RMSProp"