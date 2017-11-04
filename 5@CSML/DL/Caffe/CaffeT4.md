# Caffe Tutorial 4: Blob,Net, Layer, Solver

## 4.1 Blob

#### Blob是Caffe的基本数据结构，具有CPU和GPU之间同步的能力,它是4维的数组(Num, Channels, Height, Width)。设Blob数据维度为 number N x channel K x height H x width W，Blob是row-major保存的，因此在(n, k, h, w)位置的值物理位置为((n * K + k) * H + h) * W + w，其中Number/N是batch size。
#### Blob同时保存了data和diff(梯度)，访问data或diff有两种方法:

	  const Dtype* cpu_data() const;
	  void set_cpu_data(Dtype* data);
	  const int* gpu_shape() const;
	  const Dtype* gpu_data() const;
	  void set_gpu_data(Dtype* data);
	  const Dtype* cpu_diff() const;
	  const Dtype* gpu_diff() const;
	  Dtype* mutable_cpu_data();
	  Dtype* mutable_gpu_data();
	  Dtype* mutable_cpu_diff();
	  Dtype* mutable_gpu_diff();

## 4.2 Net

Net由一系列的Layer组成(无回路有向图DAG)，Layer之间的连接由一个文本文件描述。模型初始化Net::Init()会产生blob和layer并调用Layer::SetUp。在此过程中Net会报告初始化进程。这里的初始化与设备无关，在初始化之后通过Caffe::set_mode()设置Caffe::mode()来选择运行平台CPU或GPU，结果是相同的。

## 4.3 Layer

所有的Pooling，Convolution，apply nonlinearities等操作都在这里实现。在Layer中input data用bottom表示output data用top表示。每一层定义了三种操作setup（Layer初始化）, forward（正向传导，根据input计算output）, backward（反向传导计算，根据output计算input的梯度）。forward和backward有GPU和CPU两个版本的实现。

![](https://i.imgur.com/i4MrXbp.png)



## 4.4 Solver
![](https://i.imgur.com/DIhbdtc.png)



### Reference
[http://blog.csdn.net/danieljianfeng/article/details/42931721](http://blog.csdn.net/danieljianfeng/article/details/42931721)