#include <iostream>
using namespace std;

int interpolationSearch(int *arr, int size, int target)
{
	int low = 0, high = size - 1;
	int index = -1;
	while (low <= high && target >= arr[low] && target <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == target)
				index = low;
			break;
		}
		int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
		if (arr[pos] == target)
		{
			index = pos;
			break;
		}
		if (arr[pos] < target)
			low = pos + 1;
		else
			high = pos - 1;
	}
	if (index == -1)
		cout << "Item not in list" << endl;
	else
		cout << "Item found at index: " << index << endl;
	return index;
}

int main()
{
	int size;
	cout << "Input size: ";
	cin >> size;

	int *arr = new int[size];

	cout << "Enter sorted, uniformly distributed numbers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> arr[i];
	}

	int target;
	cout << "Enter target: ";
	cin >> target;

	int result = interpolationSearch(arr, size, target);

	delete[] arr;
	return 0;
}
