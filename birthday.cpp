#include <iostream>

using namespace std;

double getP(int n) {
	if (n < 0) return -1;
	if (n > 365) return 1;
	double result = 1;
	for (int i = 0; i < n; i++)
		result *= (double)(365 - i) / 365;
	return 1 - result;
}

int getPerP(double d) {
	int n = d * 100;
	if (n == 0) return 0;
	if (n == 100) return 100;
	int ten = n / 10;
	int one = n % 10;
	if (one < 5)
		one = 5 - one > 2.5 ? 0 : 5;
	else {
		if (10 - one > 2.5)
			one = 5;
		else {
			ten += 1;
			one = 0;
		}
	}
	return 10 * ten + one;
}

int main(void) {
	cout << "/----------------------Birthday Problem Graph----------------------/" << endl;
	for (int i = 100; i >= 0; i -= 5) {
		printf("%3d ", i);
		for (int j = 0; j <= 60; j += 1) {
			if (i == getPerP(getP(j)))
				cout << "o";
			else
				cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 15; i++)
		cout << " ";
	cout << "# x axis: 0 to 60 step 1 || y axis: n percent(s)" << endl;
	return 0;
}

