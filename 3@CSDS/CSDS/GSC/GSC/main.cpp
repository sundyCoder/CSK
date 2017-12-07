
#include "array/array.hpp"
#include "divideConquer/csDC.hpp"
#include "sort/sort.hpp"
#include "tree/bt.hpp"
#include "tree/AVLTree.hpp"
#include "tree/BST.hpp"
#include <iostream>
#include <algorithm>
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
	bit.btTreeInsert(1);
	bit.btTreeInsert(2);
	bit.btTreeInsert(3);
	bit.btTreeInsert(4);
	bit.btTreeInsert(5);
	//vector<int> vecTree = bit.btTreeTravelRe();
	//vector<int> vecTree = bit.btTreeTravelIt();
	//vector<int> vecTree = bit.btPreOrderMorris();
	//vector<int> vecTree = bit.btLevelOrderRe();
	vector<int> vecTree = bit.btLevelOrderIt();
	for (int i = 0; i < vecTree.size(); i++) {
		cout << vecTree[i] << " ";
	}
	cout << endl;

	return 0;
}

void AVLTreeTest() {
	AVLTree<int> a;
	for (int i = 0; i < 10; i++)
		a.insert(i);
	cout << "树高：" << a.height() << endl;
	cout << "前序遍历:" << endl;
	a.preOrder();

	cout << "中序遍历:" << endl;
	a.InOrder();

	cout << "后序遍历:" << endl;
	a.postOrder();

	cout << "删除元素10" << endl;
	a.remove(10);

	AVLTreeNode<int>* b = a.search_iterator(10);

	if (b != nullptr)
		cout << b->key;
	else
		cout << "无此元素" << endl;
}

void BSTest() {
	BSTree<int> t;
	t.insert(62);
	t.insert(58);
	t.insert(47);
	t.insert(51);
	t.insert(35);
	t.insert(37);
	t.insert(88);
	t.insert(73);
	t.insert(99);
	t.insert(93);
	t.insert(95);

	cout << endl << "中序遍历：" << endl;
	t.inOrder();

	cout << "最大元素:" << t.search_maximum() << endl;
	cout << "最小元素:" << t.search_minimun() << endl;

	cout << "删除元素99" << endl;
	t.remove(99);

	cout << "最大元素:" << t.search_maximum() << endl;
	t.destory();
}


int main(int argc, char** argv) {
	//sort_test();
	//divideConquerTest();
	//biTreeTest();
	//AVLTreeTest();
	BSTest();
	system("pause");
	std::cout << "Hello world!" << std::endl;
	return 0;
}