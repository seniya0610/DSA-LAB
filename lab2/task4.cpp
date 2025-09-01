#include <iostream>
using namespace std;

float* resizeArr(float* arr, int newsize, int oldsize) {
    if (newsize == oldsize) {
        return arr;
    }

    float* newArr = new float[newsize];

    int limit;
    if (oldsize < newsize) {
        limit = oldsize;  // Expanding - copy all old elements
    } else {
        limit = newsize;  // Shrinking - copy only what fits
    }

    // Copy existing elements
    for (int i = 0; i < limit; i++) {
        newArr[i] = arr[i];
    }

    // Initialize new elements to 0 if expanding
    if (newsize > oldsize) {
        for (int i = oldsize; i < newsize; i++) {
            newArr[i] = 0.0f;
        }
    }

    delete[] arr; // free old memory
    return newArr;
}

void displayExpenses(float* arr, int size) {
    cout << "\nDisplay Details:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Month " << i + 1 << ": " << arr[i] << endl;
    }
}

void calculateTotalAverage(float* arr, int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    
    float average;
    if (size > 0) {
        average = total / size;
    } else {
        average = 0;
    }
    
    cout << "\nTotal Expenses: $" << total << endl;
    cout << "Average Monthly Expense: $" << average << endl;
}

int main() {
    int n;
    cout << "Enter number of months: ";
    cin >> n;

    float* expense = new float[n];

    cout << "Enter expenses for " << n << " months:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> expense[i];
    }

    char choice;
    cout << "Add more? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int newsize;
        cout << "Enter new size: ";
        cin >> newsize;

        expense = resizeArr(expense, newsize, n);

        if (newsize > n) {
            cout << "Enter expenses for the additional " << newsize - n << " months:" << endl;
            for (int i = n; i < newsize; i++) {
                cin >> expense[i];
            }
        }

        n = newsize;
    }

    displayExpenses(expense, n);
    calculateTotalAverage(expense, n);

    delete[] expense;
    return 0;
}
