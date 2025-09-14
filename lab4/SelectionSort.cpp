#include <iostream>
using namespace std;

void Printarr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int *arr, int size) // ascending
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int size;
    cout << "Input size: ";
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "before" << endl;
    Printarr(arr, size);
    SelectionSort(arr, size);
    cout << "after" << endl;
    Printarr(arr, size);

    delete[] arr;

    return 0;
}
