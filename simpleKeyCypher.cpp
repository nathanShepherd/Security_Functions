/*
Encryption using an pre-determined key

Input format:
line 1: string to be encrypted
line 2: key used for encryption

outputs encrypted message to console

Developer: Nathan Shepherd
*/

#include <iostream>
using namespace std;

int main() {
	string e = "";
    string m = "";
    cin >> m;
    
	string alpha = "0123456789";
	
    int key;
    cin >> key;

	for (int i = 0; i < m.length(); ++i) {
		for (int k = 0; k < alpha.length(); ++k) {
			if (m[i] == alpha[k]) {
				if (alpha[k] == alpha[10 - (key % 10)]) {
					e += '0';
				}
				else {
					e += alpha[(k + key) % 10];
				}
			}
		}
	}
	cout << e;

	return 0;
}