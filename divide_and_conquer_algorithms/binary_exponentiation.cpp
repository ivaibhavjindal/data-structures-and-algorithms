#include <iostream>
#define endl "\n";

using namespace std;

// Calculate a^n (O(log(N)))
long long binExp(long a, long n)
{
    if (n == 0)
        return 1;
    long long res = binExp(a, n / 2);
    if (n % 2 == 1) // odd
        return res * res * a;
    else // even
        return res * res;
}

int main()
{
    long long a, n;
    cout << "Enter base: ";
    cin >> a;
    cout << "Enter Power: ";
    cin >> n;
    cout << a << "^" << n << ": " << binExp(a, n) << endl;
}
