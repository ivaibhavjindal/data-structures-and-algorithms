#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
        return mid;

    if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, r, x);
}

int main()
{
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter key to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}