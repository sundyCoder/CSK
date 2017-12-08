## Sundy

### Tensorflow加载graph和checkpoint

a. 加载freeze之后的pb文件
	
 	string graph = "model/odel.pb";
	Status load_graph_status = LoadGraph(graph_path, &session_);

b. 加载checkpoint文件
   
	// set up your input paths
	const string pathToGraph = "model/ckp/model_ckp.meta";
	const string checkpointPath = "model/ckp/model_ckp";
	Status status;

	// Read in the protobuf graph we exported
	MetaGraphDef graph_def;
	status = ReadBinaryProto(Env::Default(), pathToGraph, &graph_def);
	if (!status.ok()) {
		throw runtime_error("Error reading graph definition from " + pathToGraph + ": " + status.ToString());
	}

	// Add the graph to the session
	status = session_->Create(graph_def.graph_def());
	if (!status.ok()) {
		throw runtime_error("Error creating graph: " + status.ToString());
	}

	// Read weights from the saved checkpoint
	Tensor checkpointPathTensor(DT_STRING, TensorShape());
	checkpointPathTensor.scalar<std::string>()() = checkpointPath;
	status = session_->Run({ { graph_def.saver_def().filename_tensor_name(), checkpointPathTensor }, },
	{}, { graph_def.saver_def().restore_op_name() }, nullptr);
	if (!status.ok()) {
		throw runtime_error("Error loading checkpoint from " + checkpointPath + ": " + status.ToString());
	}