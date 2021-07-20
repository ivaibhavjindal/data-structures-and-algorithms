#include<bits/stdc++.h>
using namespace std;

/*
quickSort(A, l, h) {
    if(l < h) {
        pi = partition(A, l, h)

        quickSort(A, l, pi-1)
        quickSort(A, pi+1, h)
    }
}
*/

// O(N)
int partition(int arr[], int low, int high)
{
    // initialisation
	int i = low-1; // O(1)
	int pivot = arr[high]; // O(1)
	
    // perform partition (O(N))
    for(int j = low; j < high; j++) {
		if(arr[j] <= pivot) {
			i += 1; // all elements till i <= pivot
			swap(arr[i], arr[j]); // move element <= pivot to its left
		}
	}
	swap(arr[i+1], arr[high]); // move pivot to its correct position
	
    return (i+1); // index of pivot
}

// AVG = O(N * log(N)) [T(N) = 2*T(N/2) + N], WORST = O(N^2)
void quickSort(int arr[], int low, int high)
{
    // base condition (arr with more than 1 element)
	if(low < high) {
		int pi = partition(arr, low, high); // returns position of pivot(arr[high]) 

		quickSort(arr, low, pi-1); // recursive call to left arr of pivot 
		quickSort(arr, pi+1, high); // recursive call to left arr of pivot
	}
}

int main()
{
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	int a[n];
	cout << "Enter elements in array: ";
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
    quickSort(a, 0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}
