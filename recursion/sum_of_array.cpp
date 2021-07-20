#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    if (n == 0)
        return 0;
    return (sum(arr, n - 1) + arr[n]);
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
    cout << "Sum: " << sum(a, n) << endl;
}
