#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "Hello World";

    cout << "Original String: " << str << endl;

    
    cout << "AND with 127: " << endl;
    for (char c : str) {
        cout << (char)(c & 127);
    }
    cout << endl;

    cout << "XOR with 127: " << endl;
    for (char c : str) {
        cout << (char)(c ^ 127);
    }
    cout << endl;

    return 0;
}
