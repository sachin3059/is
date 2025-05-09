#include <bits/stdc++.h>
using namespace std;

// Encryption function
string encrypt(string plaintext, int key) {
    string ciphertext = "";
    int len = plaintext.length();

    // Padding with '_'
    while (len % key != 0) {
        plaintext += '_';
        len++;
    }

    // Column-wise read
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < len / key; row++) {
            ciphertext += plaintext[row * key + col];
        }
    }

    return ciphertext;
}

// Decryption function
string decrypt(string ciphertext, int key) {
    string plaintext = "";
    int len = ciphertext.length();
    int rows = len / key;

    vector<char> temp(len);

    // Fill characters in row-wise from columnar ciphertext
    int index = 0;
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < rows; row++) {
            temp[row * key + col] = ciphertext[index++];
        }
    }

    // Reconstruct plaintext
    for (char c : temp) {
        if (c != '_') plaintext += c;  // remove padding
    }

    return plaintext;
}

// Main function for testing
int main() {
    string message = "HELLO WORLD";
    int key = 4;

    string encrypted = encrypt(message, key);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}



/*

H E L L
O   W O
R L D _


*/