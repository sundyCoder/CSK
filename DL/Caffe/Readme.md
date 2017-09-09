##Deep learning of Caffe
##1. Source code.
###1.Some popular caffe repository.
[https://github.com/BVLC/caffe/tree/windows](https://github.com/BVLC/caffe/tree/windows)

[https://github.com/happynear/caffe-windows](https://github.com/happynear/caffe-windows)

###2. Read Caffe Source code
1.Debug[]()

2. [Implement L2 Normalization Layer in Caffe](http://freesouls.github.io/2015/08/30/caffe-implement-l2-normlization-layer/)

###3. Usage(windows)
####0. Query the gpu devices.

	caffe device_query -gpu all
	
####1. Train a model.
 
	caffe train --solver=examples/mnist/lenet_solver.prototxt -gpu=0

####2. Test a model.
	
	caffe test -model=examples/mnist/lenet_train_test.prototxt -weights=examples/mnist/lenet_iter_361.caffemodel -gpu=0

####3. Feature extract
 
####Using the feature extract tools:  
	E:\3rd_party\caffe\Build\x64\Release\extract_features.exe models/bvlc_reference_caffenet/bvlc_reference_caffenet.caffemodel examples/_temp/imagenet_val.prototxt fc7 examples/_temp/features 10 leveldb

####4. Convert image data to lmdb.
	1. convert_imageset --shuffle  --resize_height=256 --resize_width=256 ./ train/file.txt ./train/train_lmdb --backend='lmdb'
	2. convert_imageset --shuffle  --resize_height=256 --resize_width=256 ./ test/file.txt ./test/test_lmdb  --backend='lmdb'
	

####5. Convert csv data to lmdb
 
[http://www.cnblogs.com/kisstea/p/5315659.html](http://www.cnblogs.com/kisstea/p/5315659.html)

[http://research.beenfrog.com/code/2015/05/04/write-leveldb-lmdb-using-python.html](http://research.beenfrog.com/code/2015/05/04/write-leveldb-lmdb-using-python.html)

		import lmdb
		import numpy as np
		import cv2
		import caffe
		from caffe.proto import caffe_pb2
		
		#basic setting
		lmdb_file = 'lmdb_data'
		batch_size = 256
		
		# create the leveldb file
		lmdb_env = lmdb.open(lmdb_file, map_size=int(1e12))
		lmdb_txn = lmdb_env.begin(write=True)
		datum = caffe_pb2.Datum()
		
		item_id = -1
		for x in range(1000):
		    item_id += 1
		
		    #prepare the data and label
		    data = np.ones((3,64,64), np.uint8) * (item_id%128 + 64) #CxHxW array, uint8 or float
		    label = item_id%128 + 64
		
		    # save in datum
		    datum = caffe.io.array_to_datum(data, label)
		    keystr = '{:0>8d}'.format(item_id)
		    lmdb_txn.put( keystr, datum.SerializeToString() )
		
		    # write batch
		    if(item_id + 1) % batch_size == 0:
		        lmdb_txn.commit()
		        lmdb_txn = lmdb_env.begin(write=True)
		        print (item_id + 1)
		
		# write last batch
		if (item_id+1) % batch_size != 0:
		    lmdb_txn.commit()
		    print 'last batch'
		    print (item_id + 1)
		
		READ
		import caffe
		import lmdb
		import numpy as np
		import cv2
		from caffe.proto import caffe_pb2
		
		lmdb_env = lmdb.open('lmdb_data')
		lmdb_txn = lmdb_env.begin()
		lmdb_cursor = lmdb_txn.cursor()
		datum = caffe_pb2.Datum()
		
		for key, value in lmdb_cursor:
		    datum.ParseFromString(value)
		
		    label = datum.label
		    data = caffe.io.datum_to_array(datum)
		
		    #CxHxW to HxWxC in cv2
		    image = np.transpose(data, (1,2,0))
		    cv2.imshow('cv2', image)
		    cv2.waitKey(1)
		    print('{},{}'.format(key, label))
 
###6. Convert csv data to h5df

####1. Matlab(caffe cannot read this kind of struct data)
	
		data = double(load('expUnLabel.csv'));
		label = double(load('expUnLabel.csv'));
		
		h5create('my_example.h5','/data',size(data));
		h5create('my_example.h5','/label',size(label));
		h5write('my_example.h5','/data',data)
		h5write('my_example.h5','/label',label)
		
		h5disp('my_example.h5')

###7. Read LMDB data in python

		caffe_root = '../'  # this file should be run from {caffe_root}/examples (otherwise change this line)
		
		import sys
		sys.path.insert(0, caffe_root + 'python')
		
		
		import numpy as np
		import lmdb
		import caffe
		
		
		env = lmdb.open('mnist/mnist_train_lmdb', readonly=True)
		with env.begin() as txn:
		    raw_datum = txn.get(b'00000000')
		
		datum = caffe.proto.caffe_pb2.Datum()
		datum.ParseFromString(raw_datum)
		
		flat_x = np.fromstring(datum.data, dtype=np.double)
		x = flat_x.reshape(datum.channels, datum.height, datum.width)
		y = datum.label
		
		with env.begin() as txn:
		    cursor = txn.cursor()
		    for key, value in cursor:
		        print(key, value)

###6. Others
1. [Hacker's guide to Neural Networks](http://karpathy.github.io/neuralnets/)
2. [Caffe Regression](https://github.com/qiexing/caffe-regression)
3. [Resource](http://blog.csdn.net/danieljianfeng/article/details/43151421)

