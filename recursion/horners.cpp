#include <iostream>
using namespace std;

int horners(int a[], int m, int n, int x)
{
    if (m == n)
        return a[m];
    return (a[n] + x * horners(a, m, n + 1, x));
}

int main()
{
    int n, x;
    cout << "Enter number of constants: ";
    cin >> n;
    int a[n];
    cout << "Enter value of constants: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Polynomial: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << "x^" << i;
        if (i != 0)
            cout << " + ";
    }
    cout << "\nEnter value of x: ";
    cin >> x;
    cout << "Value of polynomial is " << horners(a, n - 1, 0, x);
    return 0;
}
