#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x)
{
    if (n == 0)
        return -1;
    if (arr[n] == x)
        return n;
    linear_search(arr, n - 1, x);
}

int main()
{
    int n, x;
    cout << "Enter the size of your array: ";
    cin >> n;
    int a[n + 1];
    cout << "Enter the elements in array: ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Enter the number you want to search in an array: ";
    cin >> x;
    int index = linear_search(a, n, x);
    if (index == -1)
        cout << "Number not found\n";
    else
        cout << "Number found at position: " << index << endl;
}
