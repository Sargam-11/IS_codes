#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform row transposition encryption
string encrypt(const string &plaintext, const vector<int> &permutation)
{
    int numRows = permutation.size();
    int numCols = (plaintext.length() + numRows - 1) / numRows;

    // Create a matrix to store the plaintext characters
    vector<vector<char> > matrix(numRows, vector<char>(numCols, ' '));

    // Fill the matrix with plaintext characters
    int index = 0;
    for (int col = 0; col < numCols; ++col)
    {
    	
        for (int row : permutation)
        {
            if (index < plaintext.length())
            {
                matrix[row][col] = plaintext[index++];
            }
            else
            {
                break;
            }
        }
    }

    // Read the ciphertext column by column
    string ciphertext;
    for (int row : permutation)
    {
        for (int col = 0; col < numCols; ++col)
        {
            if (matrix[row][col] != ' ')
            {
                ciphertext += matrix[row][col];
            }
        }
    }

    return ciphertext;
}

int main()
{
    string plaintext = "geeks for geeks";
    vector<int> permutation = {2, 0, 1, 3}; // Example permutation

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, permutation);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}

