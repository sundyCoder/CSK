#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GSC {
public:
	template <typename Dtype>
	int removeBTwice(vector<Dtype>& vec) {
		if (vec.size() <= 2) {
			return 2;
		}
		int index = 2;
		for (int i = 2; i < vec.size(); i++) {
			if (vec[index - 2] != vec[i]) {
				vec[index++] = vec[i];
			}
		}
		vec.erase(vec.begin() + index, vec.end());
		return index + 1;
	}
};


int main_exp3(int argc, char** argv) {
	vector<int> vec_test = {1,1,1,2,2,3};
	GSC gsc_test;
	int length = gsc_test.removeBTwice(vec_test);
	for_each(vec_test.begin(), vec_test.end(), [](int n) {cout << n << " "; });

	system("pause");
	return 0;
}