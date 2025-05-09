#include <bits/stdc++.h>
using namespace std;

// GCD
int find_gcd(int a, int b) {
    if (b == 0) return a;
    return find_gcd(b, a % b);
}

// Fast modular exponentiation
int binpow(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

// Extended Euclidean Algorithm
int ext_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int gcd = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Modular inverse
int cal_mod_inv(int num, int mod) {
    int x, y;
    int gcd = ext_gcd(num, mod, x, y);
    if (gcd != 1) return -1;
    return (x % mod + mod) % mod;
}

// Encrypt message
vector<int> encrypt_message(const string &msg, int e, int n) {
    vector<int> encrypted;
    for (char ch : msg) {
        encrypted.push_back(binpow((int)ch, e, n));
    }
    return encrypted;
}

// Decrypt message
string decrypt_message(const vector<int> &ciphertext, int d, int n) {
    string decrypted = "";
    for (int c : ciphertext) {
        decrypted += (char)binpow(c, d, n);
    }
    return decrypted;
}

int main() {
    // Use large primes for valid RSA
    int p = 61, q = 53;
    int n = p * q;              // n = 3233
    int phi = (p - 1) * (q - 1); // φ(n) = 3120

    int e = 17; // Common public exponent
    int d = cal_mod_inv(e, phi);

    if (d == -1) {
        cout << "Modular inverse doesn't exist. Try different 'e'.\n";
        return 1;
    }

    cout << "Public Key: (e = " << e << ", n = " << n << ")\n";
    cout << "Private Key: (d = " << d << ", n = " << n << ")\n";

    // Input message
    string msg;
    cout << "\nEnter message: ";
    getline(cin, msg);

    // Encrypt
    vector<int> encrypted = encrypt_message(msg, e, n);
    cout << "\nEncrypted message (numbers): ";
    for (int val : encrypted) cout << val << " ";
    cout << endl;

    // Decrypt
    string decrypted = decrypt_message(encrypted, d, n);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
