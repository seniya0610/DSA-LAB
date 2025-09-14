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

int getNextGap(int gap)
{
	gap = (gap * 10) / 13;
	if (gap < 1)
		return 1;
	return gap;
}

void CombSort(int *arr, int size, int &swapCount, int &compCount)
{
	int gap = size;
	bool swapped = true;
	swapCount = 0;
	compCount = 0;
	while (gap != 1 || swapped)
	{
		gap = getNextGap(gap);
		swapped = false;
		for (int i = 0; i < size - gap; i++)
		{
			compCount++;
			if (arr[i] > arr[i + gap])
			{
				int temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapCount++;
				swapped = true;
			}
		}
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

	int swapCount = 0, compCount = 0;
	CombSort(arr, size, swapCount, compCount);

	cout << "after" << endl;
	Printarr(arr, size);
	cout << "Total comparisons: " << compCount << endl;
	cout << "Total swaps: " << swapCount << endl;

	delete[] arr;
	return 0;
}
