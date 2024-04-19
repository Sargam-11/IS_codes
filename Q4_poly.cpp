#include <iostream>
#include <string>

using namespace std;

// Function to encrypt plaintext using the Vigenère Cipher
string encrypt(string plaintext, const string& key) {
    string ciphertext = "";
    int keyLength = key.length();
    int textLength = plaintext.length();

    for (int i = 0; i < textLength; ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        // Encrypt alphabetic characters
        if (isalpha(plainChar)) {
            char base = islower(plainChar) ? 'a' : 'A';
            char encryptedChar = ((plainChar - base + keyChar - 'a') % 26) + base;
            ciphertext += encryptedChar;
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

int main() {
string plaintext;
    string key;

    // Prompt the user to enter the plaintext
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Prompt the user to enter the key
    cout << "Enter the key: ";
    getline(cin, key);

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}

