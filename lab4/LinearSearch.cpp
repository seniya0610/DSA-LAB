#include <iostream>
using namespace std;

int linearSearch(int *arr, int target, int size)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Item not in list" << endl;
    }
    else
    {
        cout << "Item found at index: " << index << endl;
    }

    return index;
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

    int target;
    cout << "Enter number to search: ";
    cin >> target;

    int result = linearSearch(arr, target, size);

    delete[] arr;

    return 0;
}
