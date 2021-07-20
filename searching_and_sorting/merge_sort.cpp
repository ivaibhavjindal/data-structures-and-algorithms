#include <iostream>

using namespace std;

// O(N+M)
void merge(int larr[], int lenl, int rarr[], int lenr, int arr[], int len)
{
	int lind = 0,
		rind = 0,
		ind = 0;

	while ((lind < lenl) && (rind < lenr))
	{
		if (larr[lind] <= rarr[rind])
		{
			arr[ind++] = larr[lind++];
		}
		else
		{
			arr[ind++] = rarr[rind++];
		}
	}

	while (lind < lenl)
	{
		arr[ind++] = larr[lind++];
	}
	while (rind < lenr)
	{
		arr[ind++] = rarr[rind++];
	}
}

// O(log(N))
void mergeSort(int arr[], int len)
{
	if (len < 2)
		return;

	int mid = len / 2;

	int left[mid],
		right[len - mid];

	for (int i = 0; i < mid; i++)
	{
		left[i] = arr[i];
	}

	for (int i = mid; i < len; i++)
	{
		right[i - mid] = arr[i];
	}

	mergeSort(left, mid);
	mergeSort(right, len - mid);

	merge(left, mid, right, len - mid, arr, len);
}

int main()
{
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter elements of array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	mergeSort(arr, n);

	cout << "After mergesort: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
