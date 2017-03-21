#include <iostream>
using namespace std;

int place(int i) {
	int output = 1;
	for (int k = 1; k <= i; ++k) {
		output *= 10;
	}
	return output;
}

int isolate(int input, int index) {
	int lhs, rhs, output;
	lhs = ((input / place(index + 1)) * place(index + 1));
	rhs = (input % place(index));

	output = input - lhs - rhs;
	return output;
}

int main() {
	int m = 0;
	int c = 0;
	int digits = 0;
	cin >> m;

	//find num of digits in m
	for (int i = 0; i < 10; ++i) {
		if ((m / place(i)) < 1) {
			digits = i;
			i = 10;
		}
	}
	//cout << digits;

	//c = funct(m)
	int funct = 0;
	for (int i = 0; i < digits; ++i) {
		funct += place(i);
	}
	//cout << funct;
	/*
	1191 = 1000 + 191 = (1191 / (place(digits)) + 191
	2229 = 2229 / place(1)
	1932 = 1932 / place(3)
	6598
	*/
	int var;
	for (int i = 1; i <= digits; ++i) {
		var = isolate(m, i);
		cout << var << ' ';
		if ((var % 9) == 0) {
			funct -= place(i);
		}
	}
	//cout << funct;
	c = m + funct;
	//cout << c;

	return 0;
}