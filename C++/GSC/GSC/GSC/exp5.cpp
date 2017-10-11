#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main_exp5(int argc, char** argv) {
	//map<int, int> map_test = { {333,111}, {2,2},{33,3}, {22,2} };
	//multimap<int, int> map_test = { {11,1}, {22,2},{33,3}, {22,2} };
	unordered_map<int, int> map_test = { {1,11},{2,22},{3,33},{4,44} };
	for_each(map_test.begin(), map_test.end(), [](const auto &myMap) {
		cout << myMap.first << ":" << myMap.second << endl;
	});

	// set<int> set_test = { 1,2,3,1,2,3};
	// multiset<int> set_test = { 1,2,3,1,2,3 };
	// unordered_set<int> set_test = {3,2,1,3,2,1};
	unordered_multiset<int> set_test = { 3,2,1,3,2,1 };

	for_each(set_test.begin(), set_test.end(), [](const auto &myMap) {
		cout << myMap << endl;
	});
	system("pause");
	return 0;
}