#include<bits/stdc++.h>
using namespace std;

/*
kthSmallest(A, l, r, k) {
    pos = partition(A, l, r)

    if (pos = k-1) 
        return A[pos]
    
    else if (pos > k-1)
        return kthSmallest(A, l, pos-1, k)
    
    else
        return kthSmallest(A, pos+1, r, k)
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

// AVG => O(N) [T(N) = T(N/2) + N], WORST => O(N^2)
int kthSmallest(int arr[],int low, int high , int k)
{
	int pos = partition(arr, low, high); // find index of pivot(arr[high])
	
    // pivot is at kth positon(index = k-1)
	if(pos == k-1)
		return arr[pos];

    // if pivot on right of kth position
	else if(pos > k-1)
		return kthSmallest(arr, low, pos-1, k); // recursive call to left subarray

    // if pivot on left of kth position
	else
		return kthSmallest(arr, pos+1, high, k); // recursive call to right subarray
}

int main()
{
	int n, k;
	cout << "Enter number of elements: ";
	cin >> n;
	int a[n];
	cout << "Enter elements in array: ";
	for(int i = 0; i < n; i++)
		cin >> a[i];

	cout << "Enter k to find kth smallest element in array: ";
	cin >> k;
	cout << k <<"th smallest element: "<< kthSmallest(a, 0, n-1, k) << "\n";
}
