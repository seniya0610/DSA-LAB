#include <iostream>

using namespace std;

int main() {
    int matrixRows, matrixColumns;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> matrixRows >> matrixColumns;

    // Allocate memory for the matrix
    int** matrixData = new int*[matrixRows];
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++) {
        matrixData[rowIndex] = new int[matrixColumns];
        cout << "Enter " << matrixColumns << " values for row " << rowIndex + 1 << ": ";
        for (int columnIndex = 0; columnIndex < matrixColumns; columnIndex++) {
            cin >> matrixData[rowIndex][columnIndex];
        }
    }

    // Display the original matrix
    cout << "\nOriginal Matrix:" << endl;
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < matrixColumns; columnIndex++) {
            cout << matrixData[rowIndex][columnIndex] << "\t";
        }
        cout << endl;
    }

    // Convert to sparse matrix format (only non-zero elements)
    cout << "\nSparse Matrix Representation (Row, Column, Value):" << endl;
    cout << "Total rows: " << matrixRows << ", Total columns: " << matrixColumns << endl;
    
    int nonZeroCount = 0;
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < matrixColumns; columnIndex++) {
            if (matrixData[rowIndex][columnIndex] != 0) {
                cout << rowIndex << "\t" << columnIndex << "\t" 
                     << matrixData[rowIndex][columnIndex] << endl;
                nonZeroCount++;
            }
        }
    }
    
    cout << "Total non-zero elements: " << nonZeroCount << endl;
    float sparsity = 100.0 * (1.0 - (float)nonZeroCount / (matrixRows * matrixColumns));
    cout << "Matrix sparsity: " << sparsity << "%" << endl;

    // Clean up memory
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++) {
        delete[] matrixData[rowIndex];
    }
    delete[] matrixData;

    return 0;
}
