#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    int index, value;
    char choice;
    do {
        cout << "Enter index to update (0 to " << size - 1 << "): ";
        cin >> index;
        if (index >= 0 && index < size) {
            cout << "Value: ";
            cin >> value;
            arr[index] = value;
        } else {
            cout << "Invalid" << endl;
        }

        cout << "Update another value? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nArray: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
