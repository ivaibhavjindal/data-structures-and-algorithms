#include<bits/stdc++.h>
using namespace std;

/*
partition(A, l, h, p) 
{
    i = l-1
    piv_ind = 1
    
    for j = low to high do {
        if (A[j] = p) {
            piv_ind = j
            break
        }
    }
    
    for j = low to high do {
        if (A[j] <= p) {
            i = i + 1
            A[i], A[j] = A[j], A[i]
        }
    }
    swap(A[i+1], A[piv_ind]);
    return i+1
}
*/

// O(N)
int partition(int arr[], int low, int high, int piv)
{
    // initialisation
	int i = low-1; // O(1)
    int piv_index = 0; // O(1)

    // find index of pivot (O(N))
    for(int j = low; j < high; j++) {
        if(arr[j] == piv) {
            piv_index = j;
            break;
        }
    }

    // perform partition (O(N))
	for(int j = low; j < high; j++) {
		if(arr[j] <= piv) {
			i += 1; // all elements till i <= pivot
			swap(arr[i], arr[j]); // move element <= pivot to its left
		}
	}
    swap(arr[i+1], arr[piv]); // move pivot to its correct position 

	return (i+1); // index of pivot
}

int main()
{
	int n, p;
	cout << "Enter number of elements: ";
	cin >> n;
	int a[n];
	cout << "Enter elements in array: ";
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
    cout << "Enter element from array for partition: ";
    cin >> p;
	cout << "Position of " << p << " is at index " <<  partition(a, 0, n-1, p) << "\n";
}
