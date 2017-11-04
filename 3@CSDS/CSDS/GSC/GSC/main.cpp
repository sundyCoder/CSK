#include "sort.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;
using namespace sort;

int main(int argc, char** argv) {
	int A[] = {31,41,59,26,41,58};
	int len = sizeof(A) / sizeof(int);
	Solution<int> solu;
	//int ret = solu.insertionSort(A,len);		
	//int ret = solu.shellSort(A,len);		    

	//int ret = solu.bubbleSort(A,len);		
	//int ret = solu.quickSort(A,0,len - 1);		

	//int ret = solu.selectionSort(A, len);
	//int ret = solu.heapSort(A, len);

	//int ret = solu.mergeSort(A, 0, len -1);   

	int ret = solu.radixSort(A, len);
	//int ret = solu.countingSort(A, len);
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