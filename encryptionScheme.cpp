#include <iostream>
#include <string>
using namespace std;
/*
The encryption scheme
input:
password = a1b2c3d4e5
key = 1

encrypt: add salt, transpose by key, replace odds with evens
a1b2 --> b2c3 --> e4f5
c3d4 --> e4f5 --> b2c3
e5xx --> g5yy --> g5yy
*/
int main() {
    cout << "Enter your password: ";
    string pass;
    cin >> pass;
    
    cout << "Enter the key: ";
    int key;
    cin >> key;
    
    //FIXME: Error on input of '9' or 'y'
    // transpose by length of key
    for (int i = 0; i < pass.length(); ++i) {
        if (pass[i] > 47 && pass[i] < 58) {
            pass[i] = (pass[i] + key - 47) % (58 - 47) + 47;
        }
        if (pass[i] > 96 && pass[i] < 123) {
            pass[i] = (pass[i] + key - 96) % (26) + 96;
        }
    }
    cout << "Transposing: " << pass << endl;
    
    // add salt by length
    switch (key % 4) {
        case 1:
        pass.insert(pass.length() / 4, "x");
        pass.insert(pass.length() / 2, "x");
        pass.insert((3 * pass.length()) / 4, "x");
        break;
        
        case 2:
        pass.insert(pass.length() / 4, "x");
        pass.insert(pass.length() / 2, "x");
        break;
        
        case 3:
        pass.insert(pass.length() / 4, "x");
        break;
    };
    cout << "Adding salt: " << pass << endl;
    
    // replace odd positioned elements with even ones
    for (int i = 0; i < pass.length() - 1; i += 2) {
        char temp = pass[i];
        pass[i] = pass[i + 1];
        pass[i + 1] = temp;
    }
    cout << "Reordering: " << pass << endl;
    
    cout << "Encrypted password is: " << pass;
}