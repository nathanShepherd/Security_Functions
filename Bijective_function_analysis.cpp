/*
Bijective Relation Analysis

Developer: Nathan Shepherd

Purpose: Analyze an input and determine if it
    correlates with a bijective relation.

Input Format:
There are 2 lines in the input. 
The first line contains a single positive integer . 
The second line contains n space separated integers, 
    the values of f(1), f(2), ... f(n), respectively.

Output Format:
On a single line, output "YES" if  is bijective. 
    Otherwise, output "NO".

Sample Input:
3
1 2 3

Sample Output:
YES

E\Ideas: Take an input of k lines of n integers
    Determine if line k exhibits bijective,
    reflexive, symmetric, anti-symmetric, and/or
    transitive properties.
*/

#include <iostream>
using namespace std;

int main() {
    int length = 0;
    cin >> length;
    int y[20];
    int orderedY[20];
    int count = 0;
 
    for (int i = 0; i < length; ++i) {
        cin >> y[i];
    }
    for (int i = 0; i < length; ++i) {
        orderedY[i] = i + 1;
    }
    for (int i = 0; i < length; ++i) {
        for (int r = 0; r < length; ++r) {
            if (y[i] == orderedY[r]) {
                ++count;
                orderedY[r] = 0;
            }
        }
    }

    if (count == length) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}