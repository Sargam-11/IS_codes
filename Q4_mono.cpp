#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to generate a random permutation of the alphabet
string generateRandomKey() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    random_shuffle(alphabet.begin(), alphabet.end());
    // std::cout<<"shuffled alphabet key is : "<<alphabet<<std::endl;
    return alphabet;
}

// Function to encrypt plaintext using the Monoalphabetic Cipher
string encrypt(string plaintext, const string& key) {
    string ciphertext = "";

    // Generate encryption map
    char encryptionMap[26];
    for (int i = 0; i < 26; ++i) {
        encryptionMap[i] = key[i];
    }

    // Encrypt plaintext
    for (int i = 0; i < plaintext.length(); ++i) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            ciphertext += encryptionMap[tolower(c) - 'a'];
        } else {
            ciphertext += c; // Non-alphabetic characters remain unchanged
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
     cout << "Enter the plaintext: ";
    getline(cin, plaintext); // Read the entire line of input
    // Generate a random key
    string key = generateRandomKey();

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);
    cout << "Plaintext:  " << plaintext << endl;
    cout << "Key:        " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}

