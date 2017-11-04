#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
using namespace std;

/*
* 1. vector<T>是用dynamic array list实现的。
*/

void vector_test() {
	vector<int> vec_int = { 10,9,8,7,6 };
	vec_int.push_back(5);   // push_back()
	vec_int.pop_back();     // pop_back()

	vector<int>::iterator it;  // iterator
	if (!vec_int.empty()) {    // empty()
		for (it = vec_int.begin(); it != vec_int.end(); ++it) {
			cout << *it << std::endl;
		}
	}
	else {
		cout << "vector is empty!" << endl;
	}

	// reserve()
	vec_int.reserve(10);
	cout << "size:" << vec_int.size() << endl;  // 5
	cout << "sizeof:" << sizeof vec_int << endl;  // 16
	vec_int.erase(vec_int.begin() + 4);
	for (auto &vec : vec_int) {
		cout << vec << std::endl;
	}

	// std::accumulate 求和	
	auto aver = std::accumulate(vec_int.begin(), vec_int.end(), 0.0) / vec_int.size();
	cout << "aver: " << aver << std::endl;
	system("pause");
}

/*
* 2. list<T>列表: 是由Linked List实现的。
*/
void list_test() {
	list<int> list_test = {1,2,3,4,5};
	list_test.push_back(0);
	list_test.push_front(6);
	list<int>::iterator it;
	if (!list_test.empty()) {
		for (it = list_test.begin(); it != list_test.end(); ++it) {
			cout << *it << std::endl;   // 6,1,2,3,4,5,0
		}
	}
	list_test.pop_back();
	list_test.pop_front();
	cout << "---------" << endl;
	for (auto& li : list_test) {
		cout <<li << endl;
	}
	system("pause");
}

/*
* 3. std::deque<T>双端队列
*/
void deque_test() {
	std::deque<int> deque_test(5);
	std::deque<int>::reverse_iterator rit = deque_test.rbegin();

	int i = 0;
	for (rit = deque_test.rbegin(); rit != deque_test.rend(); ++rit)
		*rit = ++i;

	std::cout << "mydeque contains:";
	for (std::deque<int>::iterator it = deque_test.begin(); it != deque_test.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	system("pause");
}

/*
* 4. set<t> 集合， 是由二叉树实现的
*/
void set_test() {
	std::set<int> myset;
	std::set<int>::iterator it;
	std::pair<std::set<int>::iterator, bool> ret;

	// set some initial values:
	for (int i = 1; i <= 5; ++i)
		myset.insert(i * 10);    // set: 10 20 30 40 50

	ret = myset.insert(20);               // no new element inserted

	if (ret.second == false) it = ret.first;  // "it" now points to element 20

	myset.insert(it, 25);                 // max efficiency inserting
	myset.insert(it, 24);                 // max efficiency inserting
	myset.insert(it, 26);                 // no max efficiency inserting

	int myints[] = { 5,10,15 };              // 10 already in set, not inserted
	myset.insert(myints, myints + 3);

	std::cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

/*
* 5. map<K,V>
*/
bool fncomp(char lhs, char rhs) { return lhs<rhs; }

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs<rhs;
	}
};
void map_test() {
	std::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::map<char, int> second(first.begin(), first.end());

	std::map<char, int> third(second);

	std::map<char, int, classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char, char) = fncomp;
	std::map<char, int, bool(*)(char, char)> fifth(fn_pt); // function pointer as Compare
	system("pause");
}

int main(int argc, char** argv) {
	//vector_test();
	//list_test();
	//deque_test();
	//set_test();
	system("pause");
	return 0;
}