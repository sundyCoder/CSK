bool load_graph(std::string path_graph_file){
	GraphDef graph_def;
	// Initialize a tensorflow session
	Session* session;

	std::cout << "Initialize start" << "\n";
	Status status = NewSession(SessionOptions(), &session);
	if (!status.ok()) {
			std::cout << status.ToString() << "\n";
			return false;
	}

	// Read in the protobuf graph we exported
	// (The path seems to be relative to the cwd. Keep this in mind
	// when using `bazel run` since the cwd isn't where you call
	// `bazel run` but from inside a temp folder.)
	status = ReadBinaryProto(Env::Default(), path_graph_file, &graph_def);
	if (!status.ok()) {
			std::cout << status.ToString() << "\n";
			return false;
	}

	// Add the graph to the session
	status = session->Create(graph_def);
	if (!status.ok()) {
			std::cout << status.ToString() << "\n";
			return false;
	}

	//Restore graph training status
	std::vector<string> vNames;
	int node_count = graph_def.node_size();
	for (int i = 0; i < node_count; i++){
			auto n = graph_def.node(i);
			if (n.name().find("nWeights") != std::string::npos){
					vNames.push_back(n.name());
			}
	}

	std::vector<tensorflow::Tensor> nnOutput;
	status = session->Run({}, vNames, {}, &nnOutput);
	if (!status.ok()) {
			std::cout << status.ToString() << "\n";
			return false;
	}

	//Using graph
	tensorflow::Tensor features(DT_FLOAT, TensorShape({4, 8}));
	auto features_mat = features.flat<float>();
	for (int i = 0; i < 4 * 8; ++i){
			features_mat(i) = i;
	}

	std::vector<std::pair<string, tensorflow::Tensor>> inputs = {{ "input_x", features }};

	// The session will initialize the outputs
	std::vector<tensorflow::Tensor> outputs;

	// Run the session, evaluating our "c" operation from the graph
	Status status = session->Run(inputs, {"c:0"}, {}, &outputs);
	if (!status.ok()) {
			std::cout << status.ToString() << "\n";
			return false;
	}

	auto output_indices = outputs[0].flat_inner_dims<float>();
	for (int i = 0; i < 3; ++i){
			std::cout<<output_indices(i)<<"\n";
	}

	return true;
}
