## Sundy
### 1. 将Opencv中的Mat转化为Tensorflow中的Tensor

	int mat2Tensor(std::vector<cv::Mat>& mats, Tensor& inputImg) {
		for (int mt = 0; mt < mats.size(); mt++) {
			cv::Mat mat= mats[mt];
			mat.convertTo(mat, CV_32FC3);	
			int width = mat.cols;
			int height = mat.rows;
			int depth = 3;
	
			auto inputImageMapped = inputImg.tensor<float, 4>();
			//Copy all the data over
			for (int y = 0; y < height; ++y) {
				const float* source_row = ((float*)mat.data) + (y * width * 3);
				for (int x = 0; x < width; ++x) {
					const float* source_pixel = source_row + (x * 3);
					inputImageMapped(mt, y, x, 0) = source_pixel[2];
					inputImageMapped(mt, y, x, 1) = source_pixel[1];
					inputImageMapped(mt, y, x, 2) = source_pixel[0];
				}
			}
		}		
		return 0;
	}
