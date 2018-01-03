## Sundy

### Caffe SSD

### 1. Environment

	export PATH=/usr/local/cuda-8.0/bin${PATH:+:${PATH}}
	export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
	export CUDA_DIR=/usr/local/cuda-8.0
	export PYTHONPATH=/home/jlchen/dl/caffe/python:$PYTHONPATH

### 2.下载,编译及测试ssd源码
git clone https://github.com/weiliu89/caffe.git

按照目录中修改[Makefile.config](./Makefile.config.txt)
还有对应的[Makefile](./Makefile)

### 3.编译python接口
	make -j8  多核编译,时间较长
	make pycaffe

### 4.下载训练好的模型

[下载链接](https://drive.google.com/file/d/0BzKzrI_SkD1_WVVTSmQxU0dVRzA/view)，文件名为models_VGGNet_VOC0712_SSD_300x300.tar.gz，解压至CAFFE_ROOT/目录下

### 5 下载VOC2007数据
	cd $CAFFE_ROOT/data
	wget http://host.robots.ox.ac.uk/pascal/VOC/voc2012/VOCtrainval_11-May-2012.tar
	wget http://host.robots.ox.ac.uk/pascal/VOC/voc2007/VOCtrainval_06-Nov-2007.tar
	wget http://host.robots.ox.ac.uk/pascal/VOC/voc2007/VOCtest_06-Nov-2007.tar
	tar -xvf VOCtrainval_11-May-2012.tar
	tar -xvf VOCtrainval_06-Nov-2007.tar
	tar -xvf VOCtest_06-Nov-2007.tar

### 6. 产生LMDB格式数据集文件
	在data/VOC0712/中生成trainval.txt, test.txt, and test_name_size.txt in
	可以通过修改create_list.sh和create_data.sh来针对自己的数据集产生LMDB文件
	
	cd $CAFFE_ROOT
	./data/VOC0712/create_list.sh
	./data/VOC0712/create_data.sh

产生的trainval和test数据位于CAFFE_ROOT/data/VOCdevkit/VOC0712/lmdb/VOC0712_trainval_lmdb和CAFFE_ROOT/data/VOCdevkit/VOC0712/lmdb/VOC0712_test_lmdb


### 7.测试源码
	score_ssd_pascal.py里面的test_image_num应该是4952的，源程序有报相关错误可以改一下
	
	cd $CAFFE_ROOT
	python examples/ssd/score_ssd_pascal.py
	应该会得到0.77*左右的MAP score，说明模型可以正常运行

### 8.制作自己的训练数据集
	https://github.com/hyzhan/make_dataset

### 9. 修改$CAFFE_ROOT/data/$dataset_name/下labelmap_voc.prototxt
	
	name: "cat" # xml文件中的类别名
	label: 1
	display_name: "Cat" # 检测时显示的类别名

### 10. 修改训练文件$CAFFE_ROOT/data/example/ssd/ssd_pascal.py

	改了数据集文件夹名称的话讲程序路径里面的VOC0712都替换为你的数据集名称$dataset_name，否则不需要修改，为了不要覆盖原来的模型建议修改数据集名称
	类别数：num_classes = open(label_map_file).read().count(‘label’)
	测试图片数量：num_test_image = len(open(name_size_file).readlines())
	(4)$CAFFE_ROOT/example/ssd/ssd_pascal.py参数设置
	
	solver_param 中’max_iter’: 120000, 表示最大迭代次数
	solver_param 中’test_interval’: 10000, 每次评估模型效果的间隔迭代次数，用于观察是否收敛及过拟合
	其他参数可酌情修改

### 11. 开始训练
	cd $CAFFE_ROOT
	python example/ssd/ssd_pascal.py
	成功训练后在ssd_pascal.py文件中的job_dir路径下生成日志文件，snapshot_dir路径下存有断点模型，训练中断后会从最大迭代次数继续训练，

### 14.(五)测试训练结果
	(1)修改example/ssd/score_ssd_pascal.py文件
	修改方式与ssd_pascal.py相同，其中在det_eval_param添加’show_per_class_result’: True参数可现实每个类别的AP（average precision）
	
	(2)进行测试
	
	cd $CAFFE_ROOT
	python example/ssd/score_ssd_pascal.py
