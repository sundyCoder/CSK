#include "sort/sort.hpp"
#include "divideConquer/csDC.hpp"
#include "tree/bt.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <chrono>

using namespace std;
using namespace sort;
using namespace csdc;
using namespace bitree;

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

int biTreeTest() {
	BItree<int> bit;
	TreeNode<int>* root = (TreeNode<int> *)bit.newNode(1);
	root->left = (TreeNode<int> *)bit.newNode(2);
	root->right = (TreeNode<int> *)bit.newNode(3);
	root->left->left = (TreeNode<int> *)bit.newNode(4);
	root->left->right = (TreeNode<int> *)bit.newNode(5);
	vector<int> vecTree = bit.preorderTraversalRe(root);
	for (int i = 0; i < vecTree.size(); i++) {
		cout << vecTree[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	//sort_test();
	//divideConquerTest();
	biTreeTest();
	system("pause");
	return 0;
}