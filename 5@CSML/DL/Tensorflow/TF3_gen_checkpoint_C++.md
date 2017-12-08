## Sundy

### Tensorflow C++训练生成checkpoint

	Tensor model_string(DT_STRING, TensorShape({ 1, 1 }));
	std::string step_string = "model_step_" + std::to_string(iterations_ / step);
	model_string.matrix< std::string >()(0, 0) = save_path + step_string;
	TF_CHECK_OK(session->Run({ { "save/Const:0", model_string } }, {}, { "save/control_dependency" }, nullptr));
	
参数解析:

	TF_CHECK_OK(session->Run({ { "save/Const:0", model_string } }, {}, { "save/control_dependency" }, nullptr));
	
	参数通过以下方式得到:
	saver = tf.train.Saver()
	saver_def = saver.as_saver_def()
	# The name of the tensor you must feed with a filename when saving/restoring.
	  print saver_def.filename_tensor_name	  // save/Const:0
	# The name of the target operation you must run when restoring.
	  print saver_def.restore_op_name         // save/control_dependency
	# The name of the target operation you must run when saving.
	  print saver_def.save_tensor_name