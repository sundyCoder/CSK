#include <iostream>
#include <vector>

using namespace std;

class GSC {
public:

	template <typename Dtype>
	int searchTarget(vector<Dtype>& vec, Dtype target) {
		int first = 0, last = vec.size();
		while (first != last) {
			int mid = first + (last - first) / 2;
			if (vec[mid] == target) {
				return mid;
			}

			if (vec[first] < vec[mid]) {
				if (vec[first] <= target && target < vec[mid]) {
					last = mid;
				}
				else {
					first = mid + 1;
				}
			} else {
				if (vec[mid] <= target && target <= vec[last - 1]) {
					first = mid + 1;
				}
				else {
					last = mid;
				}
			}
		}
		return -1;
	}
};


int main_exp4(int argc, char** argv) {
	vector<int> vec = {4,5,6,7,8,9,0,1,2,3};
	int target = 8;
	GSC gsc_test;
	int index = gsc_test.searchTarget(vec,target);
	cout << index << endl;
	return 0;
}