#include <iostream>
using namespace std;

int find_max(int arr[], int n, int max)
{
    if (n == 0)
        return max;
    if (max < arr[n])
        max = arr[n];
    find_max(arr, n - 1, max);
}

int main()
{
    int n;
    cout << "Enter the size of your array: ";
    cin >> n;
    int a[n + 1];
    cout << "Enter the elements in array: ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Maximum element in the array is " << find_max(a, n, a[n]);
}
