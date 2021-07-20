#include <iostream>

using namespace std;

void selectionSort(int arr[], int len); // O(n^2)
void bubbleSort(int arr[], int len); // O(n^2)
void insertionSort(int arr[], int len); // O(n^2)
void mergeSort(int arr[], int len); // O(nlog(n)) SPACE => 0(n)
void merge(int larr[], int lenl, int rarr[], int lenr, int arr[], int len);

int main() {
	int ar[5];
	cout << "Enter Values Of Array: ";
	for(int i = 0; i < 5; i++)
		cin >> ar[i];
	mergeSort(ar, 5);
	for(int i = 0; i < 5; i++)
		cout << ar[i] << " ";
	cout << endl;
	return 0;
}

// SELECT SMALLEST NUMBERS AND ADD THEM TO BEGINNING
void selectionSort(int arr[], int len) {
	for(int i = 0; i < len - 1; i++) {
		int minIndex = i;
		for(int j = i+1; j < len; j++) {
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

// COMPARE EACH PAIR SO BIGGEST BUBBLES AT END
void bubbleSort(int arr[], int len) {
	for(int i = 1; i < len; i++) {
		for(int j = 0; j < len - i; j++) {
			if(arr[j+1] < arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp; 
			}
		}
	}
}

// ITERATE FROM BEGINNING AND INSERT NUMBER AT REQUIRED POSITION
void insertionSort(int arr[], int len) {
	// SORTING ONE BY ONE FROM LEFT
	for(int i = 1; i < len; i++) {
		int curValue = arr[i],
			curIndex = i;
		// PUSHING ARR POS TO RIGHT TILL FIND PLACE TO INSERT CURVALUE
		while((curIndex > 0) && (arr[curIndex-1] > curValue)) {
			arr[curIndex] = arr[curIndex-1];
			curIndex = curIndex - 1; 
		}
		arr[curIndex] = curValue;
	}
}

// DIVIDE AND CONQUER, RECURSIVE
// STABLE(MANTAINS RELATIVE ORDER FOR EQUAL ITEMS)
// DIVIDE ARR TO SMALLER ARRAYS AND THEN MERGE IN SORTED MANNER
void mergeSort(int arr[], int len) {
	// BASE CONDITION
	if(len < 2) {
		return;
	}
	else {
		// DIVIDING ARR TO 2 HALVES
		int mid = len/2;
		int left[mid],
			right[len - mid];
		for(int i = 0; i < mid; i++) {
			left[i] = arr[i];
		}
		for(int i = mid; i < len; i++) {
			right[i-mid] = arr[i];
		}
		// REPEATING RECURSIVELY FOR LEFT & RIGHT ARRAYS
		// TILL BOTH ARRAYS HAVE 1 ELEMENT 
		mergeSort(left, mid);
		mergeSort(right, len-mid);
		//MERGING BACK THE SPLITTED ARRAYS IN A SORTED WAY
		merge(left, mid, right, len-mid, arr, len);
	}
}

// MERGE LOGIC
void merge(int larr[], int lenl, int rarr[], int lenr, int arr[], int len) {
	int lind = 0,
		rind = 0,
		ind = 0;
	// MERGING IN SORTED MANNER
	while((lind < lenl) && (rind < lenr)) {
		if(larr[lind] <= rarr[rind]) {
			arr[ind++] = larr[lind++];
		}
		else {
			arr[ind++] = rarr[rind++];
		}
	}
	// WHEN L OR R GETS EXHAUSTED BEFORE OTHER
	while(lind < lenl) {
		arr[ind++] = larr[lind++];
	}
	while(rind < lenr) {
		arr[ind++] = rarr[rind++];
	}
}
