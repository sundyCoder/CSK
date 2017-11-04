
// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <mutex>
using namespace std;

mutex mtx;           // mutex for critical section
int share = 0;

void log() {
	try {
		throw 20;
	} catch (...) {
		cout << "divide by zero" << endl;
	}

	while (1) {
		cout << "who are you ?" << endl;
	}
}

void pause_thread()
{
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	mtx.lock();
	//log();
	share++;
	cout << "share = " << share << endl;
	mtx.unlock();
}

int main_exp2()
{
	std::thread t1(pause_thread);
	std::thread t2(pause_thread);
	std::thread t3(pause_thread);
	t1.join();
	t2.join();
	t3.join();
	std::cout << "All threads joined!\n";
	return 0;
}