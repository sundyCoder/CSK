#Sundy

###1. 判断一副图像是全黑还是全白
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

###2.方法对比
	#include <opencv/cv.hpp>
	#include <opencv2/highgui.hpp>
	#include <Windows.h>
	#include <iostream>
	
	int countNoneZeroTest(cv::Mat &bw);
	int diagScanTest(cv::Mat &image);
	
	int main(){
		cv::Mat bw = cv::imread("D:\\data\\Demo\\161111172418_1.bmp",0);
		countNoneZeroTest(bw);  //215.034 ms.
		diagScanTest(bw);       //1.76075 ms
		system("pause");
		return 0;
	}
	
	int diagScanTest(cv::Mat &image){
		if (image.empty()){
			std::cout << "Read image error!" << std::endl;
			return 0;
		}
		LARGE_INTEGER frequency;        // ticks per second
		LARGE_INTEGER t1, t2;           // ticks
		double elapsedTime;
		// get ticks per second
		QueryPerformanceFrequency(&frequency);
		// start timer
		QueryPerformanceCounter(&t1);
		cv::Mat diagImg = image.diag(); //取得图像的对角线
	
		long black = 0; long white = 0;
		long height = diagImg.rows;
		std::cout << diagImg.rows << "," << diagImg.cols << std::endl;
		for (int i = 0; i < diagImg.rows; i++){
			float value = diagImg.at<unsigned char>(i, 1);
			if (value == 0.0f) black++;
			if (value == 255.0f) white++;
		}
		std::cout << "black:" << black << ",white:" << white << std::endl;
		if (white == height && black == 0)
			std::cout << "white image!" << std::endl;
		else if (black == height && white == 0)
			std::cout << "black iamge!" << std::endl;
		else
			std::cout << "normal image!" << std::endl;
		// stop timer
		QueryPerformanceCounter(&t2);
		// compute and print the elapsed time in millisec
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
		std::cout << "CS-Timer(cvMatToQImage):" << elapsedTime << " ms.\n";   //sundy
		return 0;
	}
	
	int countNoneZeroTest(cv::Mat &bw){
		LARGE_INTEGER frequency;        // ticks per second
		LARGE_INTEGER t1, t2;           // ticks
		double elapsedTime;
		// get ticks per second
		QueryPerformanceFrequency(&frequency);
		// start timer
		QueryPerformanceCounter(&t1);
		int count = cv::countNonZero(bw);
		// stop timer
		QueryPerformanceCounter(&t2);
		// compute and print the elapsed time in millisec
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
		std::cout << "CS-Timer(cvMatToQImage):" << elapsedTime << " ms.\n";   //sundy
		if ((count == 0)){
			std::cout << "Receive origin mat is whole black from control.";
			return -1;
		}
		else if (count == bw.cols*bw.rows){
			std::cout << "Receive origin mat is whole white from control.";
			return -1;
		}
		else{
			std::cout << "normal image!" << std::endl;
		}
	}