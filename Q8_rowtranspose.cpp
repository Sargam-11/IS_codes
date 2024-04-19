#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


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
        for (size_t i = 0; i < permutation.size(); ++i)
        {
            int row = permutation[i];        
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
    for (size_t i = 0; i < permutation.size(); ++i)
    {
        int row = permutation[i];
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


int main(){
    string plaintext;
    cout << "Enter the plaintext : ";
    cin >> plaintext;
	 int permutation_array[] = {2, 0, 1, 3}; // Example permutation

    // Initialize the vector using constructor
    vector<int> permutation(permutation_array, permutation_array + sizeof(permutation_array) / sizeof(permutation_array[0]));
 
    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, permutation);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}

