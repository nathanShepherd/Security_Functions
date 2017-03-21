/*
Simple transposition encryption scheme

Purpose:
Given some input string m, whose cardinality is less than 10.
Transpose m to the right one value (ie. 1 --> 2, 9 --> 0).
Print encrypted string, e, to the console

Developer: Nathan Shepherd
*/
#include <iostream>
using namespace std;

int main() {
	string m = "";
	string e = "";
	string alpha = "0123456789";
	cin >> m;

	for (int i = 0; i < m.length(); ++i) {
		for (int k = 0; k < alpha.length(); ++k) {
			if (m[i] == alpha[k]) {
				if (alpha[k] == '9') {
					e += '0';
				}
				else {
					e += alpha[k + 1];
				}
			}
		}
	}
	cout << e;

	return 0;
}