#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main_emplace(int argc, char** argv) {
	//std::multimap<std::string, std::string> m;
	std::map<std::string, std::string> m;

	// uses pair's move constructor
	m.emplace(std::make_pair(std::string("a"), std::string("a")));

	// uses pair's converting move constructor
	m.emplace(std::make_pair("b", "abcd"));

	// uses pair's template constructor
	m.emplace("d", "ddd");
	m.emplace("d", "ddd");

	// uses pair's piecewise constructor
	m.emplace(std::piecewise_construct, std::forward_as_tuple("c"), std::forward_as_tuple(10, 'c'));
	//m.try_emplace("c", 10, 'c');
	// as of C++17, m.try_emplace("c", 10, 'c'); can be used

	for (const auto &p : m) {
		std::cout << p.first << " => " << p.second << '\n';
	}

	system("pause");
	return 0;
}
