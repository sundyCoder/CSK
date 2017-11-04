/************************************************************************/
/*               动态数组的分配，Vector                                  */
/************************************************************************/

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>

#define ROWS 10
#define COLS 10
using namespace std;

void print_vector(vector<int> vec) {
	for_each(vec.begin(), vec.end(), [](int v_) {cout << v_ << " "; });
	return;
}

int main_exp0(int argc, char** argv) {
	// 1. init array
	float** array = new float*[ROWS];
	for (int i = 0; i < ROWS; i++) {
		array[i] = new float[COLS];
	}

	// 1.1 assign value and show the value
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			array[i][j] = (i + j) * 1.0f;
			cout << std::setprecision(5) << array[i][j] << " ";
		}
		cout << endl;
	}

	// 2. int vector
	vector <vector<float>> ary(ROWS, vector<float>(COLS, 0));
	// 2.1 assign value and show the value
	for_each(
		ary.begin(), ary.end(), [](vector<float> vec) {       // scan the vector<vector<float>>
		for_each(vec.begin(), vec.end(), [](float v_) {  // scan the vector<float>
			cout << v_ << " ";
		});
		cout << endl;
	});

	system("pause");
	return 0;
}
