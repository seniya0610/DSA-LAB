// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
	int rows;
	int cols;

	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter col: ";
	cin >> cols;

	//create 2d array
	int** seats = new int*[rows];
	for (int i = 0; i < rows; i++) {
		seats[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			seats[i][j] = 0;
		}
	}

	cout << "\nEnter Seat status: \n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "Seat[" << i << "][" << j << "]: (0 or 1) ";
			cin >> seats[i][j];

			if (seats[i][j] != 0 && seats[i][j] != 1) {
				cout << "Invalid input. Auto status set to 0." << endl;
				seats[i][j] = 0;
			}
		}
	}


	cout << "\nOutput:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << seats[i][j] << " ";
		}
		cout << endl;
	}
}
