#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <algorithm>
#include <atomic>
using namespace std;

std::atomic<int> flag_ = 0;

int task1(int par1) {
	flag_ = 1;
	std::cout << "task1" << std::endl;
	return par1;
}

int task2(int par1, int par2) {
	std::cout << "task2" << std::endl;

	return par1 + par2;
}

int task3(int par1, int par2, int par3) {
	std::cout << "task3" << std::endl;

	return par1 + par2 + par3;
}


int main_mulit(int argc, char** argv) {
	std::vector<std::thread> workers_;
	workers_.push_back(std::thread(&task1, 2));
	workers_[0].detach();
	workers_.push_back(std::thread(&task2, 2,3));
	workers_.push_back(std::thread(&task3, 2,3,4));
    
	for_each(workers_.begin(), workers_.end(), [](auto& worker) {worker.join(); });
	system("pause");
	return 0;
}