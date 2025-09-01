#include <iostream>
using namespace std;

int main() {

	int students;
	cout << "enter number of students: ";
	cin >> students;

	int** arr = new int*[students];
	int* courses = new int[students];

	for (int i = 0; i < students; i++) {
		cout << "Enter number of courses for student " << i + 1 << ": ";
		cin >> courses[i];

		arr[i] = new int[courses[i]];

		cout << "Enter marks for student " << i + 1 << " " << courses[i] << " course: ";
		for (int j = 0; j < courses[i]; j++) {
			cin >> arr[i][j];
		}
	}

	cout << "Student Averages:" << endl;
	for (int i = 0; i < students; i++) {
		float sum = 0;
		for (int j = 0; j < courses[i]; j++) {
			sum += arr[i][j];
		}
		float avg = sum / courses[i];
		cout << "Student " << i + 1 << " average: " << avg << endl;
	}

	for (int i = 0; i < students; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] courses;
}
