#include <limits>
#include <iostream>
#include <vector>
using namespace std;

namespace sort {

	template <typename Dtype>
	class Solution {
	public:
		explicit Solution() {};
		virtual ~Solution() {};

		// 1. Comparison based sorting algorithm
		// 插入排序
		int insertionSort(Dtype A[], int N);              // 直接插入排序
		int shellSort(Dtype A[], int N);                  // 希尔排序

		// 交换排序
		int bubbleSort(Dtype A[], int N);                 // 冒泡排序
		int quickSort(Dtype A[], int low, int high);      // 快速排序

		// 选择排序
		int selectionSort(Dtype A[], int N);              // 直接选择排序
		void heapBuild(Dtype a[], int root, int length);
		int heapSort(Dtype a[], int N);                   // 堆排序

		// 归并排序
		int merge(Dtype A[], int p, int q, int r);
		int mergeSort(Dtype A[], int p, int r);

		//2. Non-comparison sorting algorithm
		int countSort(int A[], int N, int exp);
		int radixSort(int A[], int N);              // 基排序
		int countSort(Dtype A[], int N);              // 计数排序
		int bucketSort(float A[], int N);             // 桶排序

	public:
		int inf = std::numeric_limits<int>::max();
	};


	//辅助交换函数  
	template <typename Dtype>
	void swaptwo(Dtype *a, Dtype *b) {
		Dtype temp = *a;
		*a = *b;
		*b = temp;
	}

	//获取数组中的最大值
	int getMax(int A[], int N) {
		int max = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] > max) {
				max = A[i];
			}
		}
		return max;
	}

	int getMin(int A[], int N) {
		int min = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] < min) {
				min = A[i];
			}
		}
		return min;
	}

	/*
	* 1. 插入排序(insertion sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::insertionSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}

		for (int j = 1; j < N; j++) {
			int key = A[j];
			int i = j - 1;
			while (i >= 0 && A[i] > key) {
				A[i + 1] = A[i];
				i--;
			}
			A[i + 1] = key;
		}
		return 1;
	}

	/*
	* 2. 希尔排序(shell sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::shellSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}

		Dtype temp = 0;
		for (int gap = N / 2; gap >= 1; gap = gap / 2) {
			for (int i = gap; i < N; i++) {
				for (int j = i; j >= gap && A[j] < A[j - gap]; j -= gap) {
					temp = A[j];
					A[j] = A[j - gap];
					A[j - gap] = temp;
				}
			}
		}

		return 1;
	}

	/*
	* 3. 冒泡排序(Bubble Sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::bubbleSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}
		Dtype temp = 0;
		for (int i = N - 1; i > 0; --i) {
			bool exchange = false;
			for (int j = 0; j < i; j++) {
				if (A[j + 1] < A[j]) {
					exchange = true;
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
			if (!exchange) {
				return 1;
			}
		}
		return 1;
	}

	/*
	* 4. quickSort(快速排序)
	*/
	/* This function takes last element as pivot, places
	the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
	to left of pivot and all greater elements to right
	of pivot */
	template <typename Dtype>
	int partition(Dtype arr[], int low, int high) {
		Dtype pivot = arr[high];    // pivot
		int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++) {
			// If current element is smaller than or
			// equal to pivot
			if (arr[j] <= pivot) {
				i++;    // increment index of smaller element
				swaptwo(&arr[i], &arr[j]);
			}
		}
		swaptwo(&arr[i + 1], &arr[high]);
		return (i + 1);
	}

	/* The main function that implements QuickSort
	arr[] --> Array to be sorted,
	low  --> Starting index,
	high  --> Ending index */
	template <typename Dtype>
	int Solution<Dtype>::quickSort(Dtype arr[], int low, int high) {
		if (low < high) {
			/* pi is partitioning index, arr[p] is now
			at right place */
			Dtype pi = partition(arr, low, high);

			// Separately sort elements before
			// partition and after partition
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
		else {
			return 0;
		}
		return 1;
	}

	/* Function to print an array */
	void printArray(int arr[], int size)
	{
		int i;
		for (i = 0; i < size; i++)
			cout<<arr[i];
		cout << endl;
	}

	/*
	* 5. selectionSort(选择排序)
	*/
	template <typename Dtype>
	int Solution<Dtype>::selectionSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}
		Dtype temp = 0;
		int min = 0;
		for (int i = 0; i < N - 1; i++) {
			min = i;
			for (int j = i + 1; j < N; j++) {
				if (A[j] < A[min]) {
					min = j;
				}
			}
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
		return 1;
	}

	/*
	*  6. 堆排序（大根堆，小根堆，重要在建堆。  实现的数据结构有priority_queue）
	*/
	//堆排序的核心是建堆,传入参数为数组，根节点位置，数组长度  
	template <typename Dtype>
	void Solution<Dtype>::heapBuild(Dtype a[], int root, int length) {
		int lchild = root * 2 + 1;   //根节点的左子结点下标  
		if (lchild < length) {        //左子结点下标不能超出数组的长度  
			int flag = lchild;       //flag保存左右节点中最大值的下标  
			int rchild = lchild + 1; //根节点的右子结点下标  
			if (rchild < length) {   //右子结点下标不能超出数组的长度(如果有的话) 
				if (a[rchild] > a[flag]) {//找出左右子结点中的最大值  
					flag = rchild;
				}
			}
			if (a[root] < a[flag]) {
				//交换父结点和比父结点大的最大子节点  
				swaptwo(&a[root], &a[flag]);
				//从此次最大子节点的那个位置开始递归建堆  
				heapBuild(a, flag, length);
			}
		}
	}

	template <typename Dtype>
	int Solution<Dtype>::heapSort(Dtype a[], int N) {
		for (int i = N / 2; i >= 0; --i) { //从最后一个非叶子节点的父结点开始建堆 
			heapBuild(a, i, N);
		}

		for (int j = N - 1; j > 0; --j) { //j表示数组此时的长度，因为len长度已经建过了，从len-1开始  
			swaptwo(&a[0], &a[j]);         //交换首尾元素,将最大值交换到数组的最后位置保存  
			heapBuild(a, 0, j);          //去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2  
		}
		return 1;
	}

	/*
	* 7. 归并排序(merge sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::merge(Dtype A[], int left, int mid, int right) {
		int n1 = mid - left + 1;
		int n2 = right - mid;
		int i = 0, j = 0, k = 0;

		int* L = new int[n1 + 1];
		int* R = new int[n2 + 1];
		for (i = 0; i < n1; i++) {
			L[i] = A[left + i];
		}

		for (j = 0; j < n2; j++) {
			R[j] = A[mid + j + 1];
		}

		L[n1] = inf;
		R[n2] = inf;

		i = 0, j = 0;
		for (k = left; k <= right; k++) {
			if (L[i] <= R[j]) {
				A[k] = L[i++];
			}
			else {
				A[k] = R[j++];
			}
		}
		delete[] L;
		delete[] R;
		return 1;
	}

	template <typename Dtype>
	int Solution<Dtype>::mergeSort(Dtype A[], int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;  //中间索引
			mergeSort(A, left, mid);       //对左边进行排序
			mergeSort(A, mid + 1, right);   //对右边进行排序
			merge(A, left, mid, right);    //归并2个有序数组
			return 1;
		}
		return 0;
	}


	/*
	* 8. radixSort(基数排序)
	*/
	template <typename Dtype>
	int Solution<Dtype>::countSort(int A[], int N, int exp) {
		int *B = (int *)malloc(sizeof(int)*N);
		for (int i = 0; i < N; i++) {
			B[i] = 0;
		}

		int max = getMax(A, N);
		int lenC = max + 1;
		int *C = (int *)malloc(sizeof(int)*(lenC));
		for (int i = 0; i < lenC; i++) {
			C[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			++C[(A[i]/exp)%10];                  // 统计每个数字出现的次数
		}
		for (int j = 1; j < lenC; j++) {     // 更新统计数组
			C[j] += C[j - 1];
		}

		for (int k = N - 1; k >= 0; k--) {    // 
			B[C[A[k]/exp]%10 - 1] = A[k];
			C[A[k]/exp%10]--;
		}
		for (int m = 0; m < N; m++) {
			A[m] = B[m];
		}
		return 1;
	}

	template <typename Dtype>
	int Solution<Dtype>::radixSort(int A[], int N) {
		int max = getMax(A, N);
		for (int exp = 1; max / exp > 0; exp *= 10) {
			countSort(A, N, exp);
		}
		return 1;
	}

	
	/*
	* 9. counSort(计数排序)
	*/
	template <typename Dtype>
	int Solution<Dtype>::countSort(Dtype A[], int N) {
		int *B = (int *)malloc(sizeof(Dtype)*N);
		for (int i = 0; i < N; i++) {
			B[i] = 0;
		}

		int max = getMax(A, N);
		int min = getMin(A, N);
		int lenC = max - min + 1;
		int *C = (int *)malloc(sizeof(Dtype)*(lenC));
		for (int i = 0; i < lenC; i++) {
			C[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			++C[A[i] - min];                  // 统计每个数字出现的次数
		}
		for (int j = 1; j < lenC; j++) {     // 更新统计数组
			C[j] += C[j - 1];
		}

		for (int k = N - 1; k >= 0; k--) {    // 根据源数据在C数组中的位置方向填充B
			B[C[A[k]] - 1] = A[k];
			C[A[k] - min]--;
		}
		for (int m = 0; m < N; m++) {
			A[m] = B[m];
		}
		return 1;
	}

	/*
	* 10.bucketSort(桶排序)
	*/
	
	template <typename Dtype>
	int Solution<Dtype>::bucketSort(float A[], int N) {
		// 1) Create n empty buckets
		std::vector<float> b[10];

		// 2) Put array elements in different buckets
		for (int i = 0; i<N; i++) {
			int bi = N*A[i]; // Index in bucket
			b[bi].push_back(A[i]);
		}

		// 3) Sort individual buckets
		for (int i = 0; i < N; i++)
			std::sort(b[i].begin(), b[i].end());

		// 4) Concatenate all buckets into arr[]
		int index = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < b[i].size(); j++)
				A[index++] = b[i][j];
		return 1;
	}
}
