#include <forward_list>
#include <iostream>
#include <algorithm>

using namespace std;

int main_forward_list(int argc, char** argv) {
	forward_list<int> fList = {1,2,3,4,5};
	fList.emplace_front(6);
	for_each(fList.begin(), fList.end(), [](int n) {cout << n << " "; });
	cout << endl;
	system("pause");
	return 0;
}