//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
///** Dynamic programming approach with optimized space usage. */
//int maximal_subarray(int *array, int n) {
//	int max_sum_so_far = 0;
//	int current_sum_so_far = 0;
//	for (int i = 0; i < n; i++) {
//		current_sum_so_far = std::max(current_sum_so_far + array[i], 0);
//		max_sum_so_far = std::max(max_sum_so_far, current_sum_so_far);
//	}
//	return max_sum_so_far;
//}
//
///** Dynamic programming approach by using reduction */
//int stocks(int *array, int n) {
//	int *deltas = (int *)malloc(n * sizeof(int));
//	deltas[0] = 0;
//	for (int i = 1; i < n; i++) {
//		deltas[i] = array[i] - array[i - 1];
//	}
//	int best = maximal_subarray(deltas, n);
//	free(deltas);
//	return best;
//}
//
//int main_stock(int argc, char** argv) {
//	int arr_test[] = {1,-2,3,4,5,-6};
//	int len = sizeof(arr_test) / sizeof(int);
//	cout<<maximal_subarray(arr_test,len);
//	cout << endl;
//	int price = stocks(arr_test, len);
//	cout << price << endl;
//	system("pause");
//	return 0;
//}
