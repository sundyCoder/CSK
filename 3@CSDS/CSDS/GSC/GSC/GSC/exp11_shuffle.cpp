#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 1. O(n^2)
void myShuffle(vector<int>& vec) {
	srand(time(0));
	unordered_set<int> numbers;
	unordered_set<int>::iterator it;
	vector<int> temp_vec;

	int length = vec.size();
	temp_vec.reserve(length);
	while (numbers.size() < 20) {
		int num = rand() % 20;
		numbers.insert(num);
	}
	for (it = numbers.begin(); it != numbers.end(); it++) {
		auto random_num = *it;
		temp_vec.push_back(vec[random_num]);
	}
	vec = temp_vec;
}

// 2. O(n)
void swap(int *a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int my_random(int begin, int end) {
	int num = rand() % (end - begin) + begin;
	return num;
}

void myShuffle2(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int random_index = my_random(i, n);
		swap(&arr[i], &arr[random_index]);
	}
}


int main_shuffle(int argc, char** argv) {
	//vector<int> vec_test = {-11,-2,-33,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	//myShuffle(vec_test);
	//for_each(vec_test.begin(), vec_test.end(),[](auto& e) {cout << e << " "; });

	int my_arr[] = { -11,-2,-33,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int len = sizeof(my_arr) / sizeof(my_arr[0]);
	myShuffle2(my_arr, len);
	for (int i = 0; i < len; i++) {
		cout << my_arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
