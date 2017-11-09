## Sundy
### Convert tensorflow checkpoint files to pb file.

tensorflow的Freezing，字面意思是冷冻，可理解为整合合并；整合什么呢，就是将模型文件和权重文件整合合并为一个文件，主要用途是便于发布。
官方解释可参考：https://www.tensorflow.org/extend/tool_developers/#freezing

这里我按我的理解翻译下，不对的地方请指正：
有一点令我们为比较困惑的是，tensorflow在训练过程中，通常不会将权重数据保存的格式文件里（这里我理解是模型文件），反而是分开保存在一个叫checkpoint的检查点文件里，当初始化时，再通过模型文件里的变量Op节点来从checkoupoint文件读取数据并初始化变量。这种模型和权重数据分开保存的情况，使得发布产品时不是那么方便，所以便有了freeze_graph.py脚本文件用来将这两文件整合合并成一个文件。

freeze_graph.py是怎么做的呢？首行它先加载模型文件，再从checkpoint文件读取权重数据初始化到模型里的权重变量，再将权重变量转换成权重 常量 （因为 常量 能随模型一起保存在同一个文件里），然后再通过指定的输出节点将没用于输出推理的Op节点从图中剥离掉，再重新保存到指定的文件里（用write_graphdef或Saver）


文件目录：tensorflow/python/tools/free_graph.py

测试文件：tensorflow/python/tools/free_graph_test.py 这个测试文件很有学习价值

参数：

总共有11个参数，一个个介绍下(必选： 表示必须有值；可选： 表示可以为空)：
	
	1、input_graph：（必选）模型文件，可以是二进制的pb文件，或文本的meta文件，用input_binary来指定区分（见下面说明）
	2、input_saver：（可选）Saver解析器。保存模型和权限时，Saver也可以自身序列化保存，以便在加载时应用合适的版本。主要用于版本不兼容时使用。可以为空，为空时用当前版本的Saver。
	3、input_binary：（可选）配合input_graph用，为true时，input_graph为二进制，为false时，input_graph为文件。默认False
	4、input_checkpoint：（必选）检查点数据文件。训练时，给Saver用于保存权重、偏置等变量值。这时用于模型恢复变量值。
	5、output_node_names：（必选）输出节点的名字，有多个时用逗号分开。用于指定输出节点，将没有在输出线上的其它节点剔除。
	6、restore_op_name：（可选）从模型恢复节点的名字。升级版中已弃用。默认：save/restore_all
	7、filename_tensor_name：（可选）已弃用。默认：save/Const:0
	8、output_graph：（必选）用来保存整合后的模型输出文件。
	9、clear_devices：（可选），默认True。指定是否清除训练时节点指定的运算设备（如cpu、gpu、tpu。cpu是默认）
	10、initializer_nodes：（可选）默认空。权限加载后，可通过此参数来指定需要初始化的节点，用逗号分隔多个节点名字。
	11、variable_names_blacklist：（可先）默认空。变量黑名单，用于指定不用恢复值的变量，用逗号分隔多个变量名字。
	用法：
	例：python tensorflow/python/tools/free_graph.py \
	--input_graph=some_graph_def.pb \ 注意：这里的pb文件是用tf.train.write_graph方法保存的
	--input_checkpoint=model.ckpt.1001 \ 注意：这里若是r12以上的版本，只需给.data-00000....前面的文件名，如：model.ckpt.1001.data-00000-of-00001，只需写model.ckpt.1001  
	--output_graph=/tmp/frozen_graph.pb 
	--output_node_names=softmax
