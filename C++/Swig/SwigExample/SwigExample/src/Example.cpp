/* File : example.c */

#include <time.h>
#include "Example.h"

Example::Example() {

}

Example::~Example() {

}

int Example::fact(int n) {
	if (n <= 1) return 1;
	else return n*fact(n - 1);
}

int Example::my_mod(int x, int y) {
	return (x%y);
}

char *Example::get_time()
{
	time_t ltime;
	time(&ltime);
	char str[26];
	ctime_s(str, sizeof str, &ltime);
	return str;
}
