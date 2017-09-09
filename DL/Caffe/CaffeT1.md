## Caffe Tutorial 1
## 1.GPU查询
	# query the first device
	caffe device_query -gpu 0

## 2.数据训练
#### 2.1 训练
	caffe train -solver examples/mnist/lenet_solver.prototxt
	# 在2号GPU上训练
	caffe train -solver examples/mnist/lenet_solver.prototxt -gpu 2
	# 在０和１号ＧＰＵ上训练 (doubling the batch size)
	caffe train -solver examples/mnist/lenet_solver.prototxt -gpu 0,1
	# 在所有GPU上训练 (multiplying batch size by number of devices)
	caffe train -solver examples/mnist/lenet_solver.prototxt -gpu all

#### 2.2 从快照中恢复训练
	caffe train -solver examples/mnist/lenet_solver.prototxt -snapshot examples/mnist/lenet_iter_5000.solverstate
#### 2.3 调优
	# fine-tune CaffeNet model weights for style recognition
	caffe train -solver examples/finetuning_on_flickr_style/solver.prototxt -weights models/bvlc_reference_caffenet/bvlc_reference_caffenet.caffemodel
### 2.3 在验证集上测试
	caffe test -model examples/mnist/lenet_train_test.prototxt -weights examples/mnist/lenet_iter_10000.caffemodel -gpu 0 -iterations 100
## 3.数据测试
	 classification examples/mnist/lenet_test.prototxt examples/mnist/lenet_iter_10000.caffemodel examples/mean.binaryproto examples/label.txt examples/draw/sundy4.png

## 4.Ｂenchmarking
	# (These example calls require you complete the LeNet / MNIST example first.)
	# time LeNet training on CPU for 10 iterations
	caffe time -model examples/mnist/lenet_train_test.prototxt -iterations 10
	# time LeNet training on GPU for the default 50 iterations
	caffe time -model examples/mnist/lenet_train_test.prototxt -gpu 0
	# time a model architecture with the given weights on the first GPU for 10 iterations
	caffe time -model examples/mnist/lenet_train_test.prototxt -weights examples/mnist/lenet_iter_10000.caffemodel -gpu 0 -iterations 10
