#Sundy
##计算cv::Mat的空间的大小

	int calCvMatSize(cv::Mat &imgMat){
		cout << "rows:" << imgMat.rows << " cols:" << imgMat.cols << endl;
		double imgKBytes = (imgMat.step[0] * (imgMat.rows)) / 1024;
		string imgSize = to_string(imgKBytes) + "KB";
		if (imgKBytes / 1024.0 > 1.0) {
			imgKBytes = imgKBytes / 1024.0;
			imgSize = to_string(imgKBytes) + "MB";
			if (imgKBytes / 1024.0 > 1.0) {
				imgKBytes = imgKBytes / 1024.0;
				imgSize = to_string(imgKBytes) + "GB";
			}
		}
		cout << "size:" << imgSize << endl;
	
		return 0;
	}