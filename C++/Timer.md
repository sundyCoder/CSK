# Sundy
## 毫秒计时器
	
	LARGE_INTEGER frequency;        // ticks per second
	LARGE_INTEGER t1, t2;           // ticks
	double elapsedTime;
	 // get ticks per second
	QueryPerformanceFrequency(&frequency);
	// start timer
	QueryPerformanceCounter(&t1);
	//do something
	xxxx
	// stop timer
	QueryPerformanceCounter(&t2);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	//std::cout << "CS-Timer(cvMatToQImage):" << elapsedTime << " ms.\n";   //sundy
