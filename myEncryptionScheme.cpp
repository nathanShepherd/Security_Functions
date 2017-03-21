#include <iostream>
#include <string>
using namespace std;
/*
The encryption scheme

input:
a1b2c3d4e5

encrypt: add salt, transpose monoalphanumeric, replace odds with evens
a1b2 --> b2c3 --> e4f5
c3d4 --> e4f5 --> b2c3
e5xx --> g5yy --> g5yy





*/
int main() {
    cout << "Enter your password: ";
    string pass;
    cin >> pass;
    
    // add salt by length
    switch (pass.length() % 4) {
        case 1:
        pass = pass + "xxx";
        break;
        
        case 2:
        pass = pass + "xx";
        break;
        
        case 3:
        pass = pass + "x";
        break;
    };
    
    // transpose monoalphanumericly
    for (int i = 0; i < pass.length(); ++i) {
        if (pass[i] > 47 && pass[i] < 58) {
            pass[i] = (pass[i] + 1 - 47) % (58 - 47) + 47;
        }
        if (pass[i] > 96 && pass[i] < 123) {
            pass[i] = (pass[i] + 1 - 96) % (26) + 96;
        }
    }
    
    // replace odd positioned elements with even ones
    for (int i = 4; i < pass.length() - 1; i = i + 5) {
        pass.insert(i, ".");
    }
    
    cout << pass;
}
