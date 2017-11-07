#include "sort.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <chrono>
using namespace std;
using namespace sort;

int main(int argc, char** argv) {
	//int A[] = {31,41,59,26,41,58};
	int A[] = {2,5,3,0,2,3,0,3};
	int len = sizeof(A) / sizeof(int);
	Solution<int> solu;
	//int ret = solu.insertionSort(A,len);		
	//int ret = solu.shellSort(A,len);		    

	//int ret = solu.bubbleSort(A,len);		
	//int ret = solu.quickSort(A,0,len - 1);		

	//int ret = solu.selectionSort(A, len);
	//int ret = solu.heapSort(A, len);

	//int ret = solu.mergeSort(A, 0, len -1);   

	//int ret = solu.radixSort(A, len);
	auto start = std::chrono::system_clock::now();
	int ret = solu.countSort(A, len);
	auto end = std::chrono::system_clock::now();
	std::cout << "It takes " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<"us.\n";
	//int ret = solu.bucketSort(A, len);
	if (ret) {
		for (int i = 0; i < len; i++) {
			std::cout << A[i] << " ";
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}