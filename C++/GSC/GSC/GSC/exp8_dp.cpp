#include <iostream>
#include <vector>
#include <minmax.h>
using namespace std;

class GSC {
public:
	//1. Triangle
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		vector<int> minlen(triangle.back());
		for (int layer = n - 2; layer >= 0; layer--) // For each layer
		{
			for (int i = 0; i <= layer; i++) // Check its every 'node'
			{
				// Find the lesser of its two children, and sum the current value in the triangle with it.
				minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
			}
		}
		return minlen[0];
	}

	/************************************************************************/
	/*2. subarray,
	Given an array of n integers, write a function shuffle that when given the
	array, shuffles the array in place such that all n! permutations of the n integers are
	equally likely. You may assume that you have a random number generator that when
	given a non-negative integer i   2
	32, can generate integers in the range r0, iq such that
	any integer in this range is equally likely. Prove that your algorithm generates every
	permutation with equal probability                                      */
	/************************************************************************/
	/** Dynamic programming approach with optimized space usage. */
	int maximal_subarray(int *array, int n) {
		int max_sum_so_far = 0;
		int current_sum_so_far = 0;
		for (int i = 0; i < n; i++) {
			current_sum_so_far = std::max(current_sum_so_far + array[i], 0);
			max_sum_so_far = std::max(max_sum_so_far, current_sum_so_far);
		}
		return max_sum_so_far;
	}

	/************************************************************************/
	/*3. Stocks. Given an array of n integers representing the price of a stock over the course
	of n days, determine the maximum profit you can make if you can buy and sell exactly
	1 stock over these n days. Provide a divide & conquer algorithm, and a dynamic
	programming algorithm. Which is better? What is the time and space complexity for
	both solutions?  */
	/************************************************************************/
	/** Dynamic programming approach by using reduction */
	int stocks(int *array, int n) {
		int *deltas = (int *)malloc(n * sizeof(int));
		deltas[0] = 0;
		for (int i = 1; i < n; i++) {
			deltas[i] = array[i] - array[i - 1];
		}
		int best = maximal_subarray(deltas, n);
		free(deltas);
		return best;
	}

};

int main_dp(int argc, char** argv) {
	//vector<vector<int>> tri_vec = { {2},{3,4},{6,5,7},{4,1,8,3} };
	//vector<int> num_test = {-2,1,-3,4,-1,2,1,-5,4};
	vector<double> prices = {10.5, -5.5, 20.0, 30.1, 15, -25};
	GSC gsc_test;
	//cout << gsc_test.minimumTotal(tri_vec) << endl;



	int arr_test[] = { 1,-2,3,4,5,-6 };
	int len = sizeof(arr_test) / sizeof(int);
	cout << gsc_test.maximal_subarray(arr_test, len);
	cout << endl;
	int price = gsc_test.stocks(arr_test, len);
	cout << price << endl;
	system("pause");
	return 0;
}