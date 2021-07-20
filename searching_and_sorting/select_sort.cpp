#include<bits/stdc++.h>
using namespace std;

/*
selectSort(A, l, r) {
    if(l < r) {
        i = kthSmallest(A, l, r, l+1)
        swap(A[l], A[i])
        selectSort(A, l+1, r)
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

// AVG => O(N) [T(N) = T(N/2) + N], WORST => O(N^2)
int kthSmallest(int arr[],int low, int high , int k)
{
	int pos = partition(arr, low, high); // find index of pivot(arr[high])
	
    // pivot is at kth positon(index = k-1)
	if(pos == k-1)
		return pos; // return index of kthSmallest element

    // if pivot on right of kth position
	else if(pos > k-1)
		return kthSmallest(arr, low, pos-1, k); // recursive call to left subarray

    // if pivot on left of kth position
	else
		return kthSmallest(arr, pos+1, high, k); // recursive call to right subarray
}

// O(N^2) [T(N) = T(N-1) + N]
void selectSort(int arr[], int low, int high) 
{
    // base condition (arr with more than 1 element)
    if(low < high) {
        int cur_element_index = kthSmallest(arr, low, high, low+1); // find correct index of element at low+1 position
        swap(arr[low], arr[cur_element_index]); // swap elem at low with correct elem
        selectSort(arr, low+1, high); // recursive call on right subarray
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
	
    selectSort(a, 0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}
