#include "sort/sort.hpp"
#include "divideConquer/csDC.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <chrono>

using namespace std;
using namespace sort;
using namespace csdc;

void sort_test() {
	//int A[] = {31,41,59,26,41,58};
	int A[] = { 2,5,3,0,2,3,0,3 };
	int len = sizeof(A) / sizeof(int);
	Solution<int> solu;
	//int ret = solu.insertionSort(A,len);		
	//int ret = solu.shellSort(A,len);		    

	//int ret = solu.bubbleSort(A,len);		
	//int ret = solu.quickSort(A,0,len - 1);		

	//int ret = solu.selectionSort(A, len);
	//int ret = solu.heapSort(A, len);

	//int ret = solu.mergeSort(A, 0, len -1);   

	auto start = std::chrono::system_clock::now();
	//int ret = solu.countSort(A, len);
	//int ret = solu.radixSort(A, len);
	float Af[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	len = sizeof(Af) / sizeof(int);
	int ret = solu.bucketSort(Af, len);
	auto end = std::chrono::system_clock::now();
	std::cout << "It takes " << std::chrono::duration_cast
		<std::chrono::microseconds>(end - start).count() << "us.\n";
	if (ret) {
		for (int i = 0; i < len; i++) {
			std::cout << Af[i] << " ";
		}
		std::cout << std::endl;
	}
}

int divideConquerTest() {
	CSDC cs;
	//double ret = cs.myPow(10,5);
	int ret = cs.mySqrt(8);
	std::cout << ret << std::endl;
	return 1;
}

int main(int argc, char** argv) {
	//sort_test();
	divideConquerTest();
	system("pause");
	return 0;
}