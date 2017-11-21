#include <iostream>
using namespace std;

namespace csdc {
	class CSDC{
	public:
		CSDC() {};
		~CSDC() {};

		// 1. 求x的n次方
		double power(double x, int n);
		double myPow(double x, int n);

		// 2. 求整数x的平方根( y< x/2 < y^2)
		int mySqrt(int x);

	};

	double CSDC::power(double x, int n) {
		if (n == 0) {
			return 1;
		}
		double v = power(x, n / 2);
		if (n % 2 == 0) {
			return v * v;
		}
		else {
			return v * v * x;
		}
	}

	double CSDC::myPow(double x, int n) {
		if (n < 0) {
			return 1.0 / power(x, -n);
		}
		else {
			return power(x, n);
		}
		return 1;
	}

	int CSDC::mySqrt(int x) {
		if (x < 2) {
			return x;
		}
		int left = 0; 
		int right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (x / mid == mid) {
				return mid;
			} else if (x / mid < mid) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		return right;
	}
}