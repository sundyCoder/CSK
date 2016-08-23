#Sundy
###Week1 OpenCV

###1. Creating a cv::Mat
![](http://i.imgur.com/9ppFThD.png)

###2. Accessing elements of a cv::Mat
![](http://i.imgur.com/Wz9m6wD.png)

###3. Expressions with cv::Mat
![](http://i.imgur.com/XS1790W.png)

###4. Color space
RGB, YUV, CMYK, LAB

###5. ROIs: Cropping a Rectangular Portion out of an Image
	 1. rectangle(local_img, corner1, corner2, Scalar(0, 0, 255));
	 2. Rect roi(x,y,width,height);
		Mat M2(img,roi);
###6.  Detecting vertical edges in an image

	#include <opencv2/opencv.hpp>
	#include <opencv2/highgui/highgui.hpp>
	
	using namespace std;
	using namespace cv;
	
	int main() {
		Mat img = imread("vertical.png", CV_LOAD_IMAGE_GRAYSCALE), img_filtered;
	
		// Filter kernel for detecting vertical edges
		float vertical_fk[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { -1, -2, 6, -2, -1 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
		// Filter kernel for detecting horizontal edges
		float horizontal_fk[5][5] = { { 0, 0, -1, 0, 0 }, { 0, 0, -2, 0, 0 }, { 0, 0, 6, 0, 0 }, { 0, 0, -2, 0, 0 }, { 0, 0, -1, 0, 0 } };
	
		Mat filter_kernel = Mat(5, 5, CV_32FC1, horizontal_fk);
	
		// Apply filter
		filter2D(img, img_filtered, -1, filter_kernel);
	
		namedWindow("Image");
		namedWindow("Filtered image");
		imshow("Image", img);
		imshow("Filtered image", img_filtered);
	
		// imwrite("filtered_image.jpg", img_filtered);
	
		while (char(waitKey(1)) != 'q') {}
	
		return 0;
	}

###7.