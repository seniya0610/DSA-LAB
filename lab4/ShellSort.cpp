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

void BubbleSort(int *arr, int size, int &swapCount, int &compCount)
{
	swapCount = 0;
	compCount = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			compCount++;
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapCount++;
			}
		}
	}
}

void InsertionSort(int *arr, int size, int &swapCount, int &compCount)
{
	swapCount = 0;
	compCount = 0;
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0)
		{
			compCount++;
			if (arr[j] > key)
			{
				arr[j + 1] = arr[j];
				swapCount++;
			}
			else
			{
				break;
			}
			j--;
		}
		arr[j + 1] = key;
	}
}

void ShellSort(int *arr, int size, int &swapCount, int &compCount)
{
	swapCount = 0;
	compCount = 0;
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i++)
		{
			int temp = arr[i];
			int j = i;
			while (j >= gap)
			{
				compCount++;
				if (arr[j - gap] > temp)
				{
					arr[j] = arr[j - gap];
					swapCount++;
				}
				else
				{
					break;
				}
				j -= gap;
			}
			arr[j] = temp;
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

	// Make copies for fair comparison
	int *arrBubble = new int[size];
	int *arrInsertion = new int[size];
	int *arrShell = new int[size];
	for (int i = 0; i < size; i++)
	{
		arrBubble[i] = arr[i];
		arrInsertion[i] = arr[i];
		arrShell[i] = arr[i];
	}

	int swapB = 0, compB = 0;
	int swapI = 0, compI = 0;
	int swapS = 0, compS = 0;

	BubbleSort(arrBubble, size, swapB, compB);
	InsertionSort(arrInsertion, size, swapI, compI);
	ShellSort(arrShell, size, swapS, compS);

	cout << "\nBubble Sort: " << endl;
	Printarr(arrBubble, size);
	cout << "Total comparisons: " << compB << endl;
	cout << "Total swaps: " << swapB << endl;

	cout << "\nInsertion Sort: " << endl;
	Printarr(arrInsertion, size);
	cout << "Total comparisons: " << compI << endl;
	cout << "Total swaps: " << swapI << endl;

	cout << "\nShell Sort: " << endl;
	Printarr(arrShell, size);
	cout << "Total comparisons: " << compS << endl;
	cout << "Total swaps: " << swapS << endl;

	delete[] arr;
	delete[] arrBubble;
	delete[] arrInsertion;
	delete[] arrShell;
	return 0;
}
