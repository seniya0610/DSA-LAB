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

void InsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int BinarySearch(int *arr, int size, int target)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
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
    InsertionSort(arr, size);
    cout << "after" << endl;
    Printarr(arr, size);

    int target;
    cout << "Enter number to search: ";
    cin >> target;

    int result = BinarySearch(arr, size, target);
    if (result != -1)
        cout << "Item found at index: " << result << endl;
    else
        cout << "Item not in list" << endl;

    delete[] arr;

    return 0;
}
