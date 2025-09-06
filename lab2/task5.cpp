#include <iostream>

using namespace std;

int main(){
    int matrixRows, matrixCols;
    cout << "Enter number of rows: ";
    cin >> matrixRows;
    cout << "Enter number of columns: ";
    cin >> matrixCols;

    int** firstMatrix = new int*[matrixRows];
    int** secondMatrix = new int*[matrixRows];
    int** resultSum = new int*[matrixRows];
    int** resultDifference = new int*[matrixRows];

    for (int row = 0; row < matrixRows; row++){
        firstMatrix[row] = new int[matrixCols];
        secondMatrix[row] = new int[matrixCols];
        resultSum[row] = new int[matrixCols];
        resultDifference[row] = new int[matrixCols];
    }

    cout << "Enter values of the first matrix:" << endl;
    for (int row = 0; row < matrixRows; row++){
        for (int col = 0; col < matrixCols; col++){
            cin >> firstMatrix[row][col];
        }
    }

    cout << "Enter values of the second matrix:" << endl;
    for (int row = 0; row < matrixRows; row++){
        for (int col = 0; col < matrixCols; col++){
            cin >> secondMatrix[row][col];
        }
    }

    for (int row = 0; row < matrixRows; row++){
        for (int col = 0; col < matrixCols; col++){
            resultSum[row][col] = firstMatrix[row][col] + secondMatrix[row][col];
            resultDifference[row][col] = firstMatrix[row][col] - secondMatrix[row][col];
        }
    }
    
    cout << "Sum of the matrices: " << endl;
    for (int row = 0; row < matrixRows; row++){
        for (int col = 0; col < matrixCols; col++){
            cout << resultSum[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Difference of the matrices: " << endl;
    for (int row = 0; row < matrixRows; row++){
        for (int col = 0; col < matrixCols; col++){
            cout << resultDifference[row][col] << " ";
        }
        cout << endl;
    }

    for (int row = 0; row < matrixRows; row++){
        delete[] firstMatrix[row];
        delete[] secondMatrix[row];
        delete[] resultSum[row];
        delete[] resultDifference[row];
    }
    delete[] firstMatrix;
    delete[] secondMatrix;
    delete[] resultSum;
    delete[] resultDifference;

    return 0;
}
