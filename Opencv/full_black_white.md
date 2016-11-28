#Sundy

###判断一副图像是全黑还是全白
	#include <iostream>
	#include <opencv2/opencv.hpp>
	#include <opencv2/highgui/highgui.hpp>
	
	using namespace std;
	using namespace cv;
	
	int main() {
		Mat image = imread("161123092504_2.png", 0);
		if (image.empty()){
			cout << "Read image error!" << endl;
			return 0;
		}
	
		Mat diagImg = image.diag(); //取得图像的对角线
		
		long black = 0;long white = 0;
		long height = diagImg.rows;
		cout << diagImg.rows << ","<<diagImg.cols << endl;	
		for (int i = 0; i < diagImg.rows; i++){
			float value = diagImg.at<unsigned char>(i, 1);
			if (value == 0.0f) black++;
			if (value == 255.0f) white++;
		}
		cout << "black:" << black << ",white:" << white << endl;
		if (white == height && black == 0)
			cout << "white image!" << endl;
		else if (black == height && white == 0)
			cout << "black iamge!" << endl;
		else
			cout << "normal image!" << endl;
		return 0;
	}