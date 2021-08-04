// https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/

#include <iostream>
using namespace std;

float findSqrt(float x, int p)
{
    long long s = 0, e = x, m = (s + e) / 2;
    float ans = 0;

    // finding integer part
    while (s <= e)
    {
        m = (s + e) / 2;
        if (m * m == x)
            return m;
        else if (m * m > x)
            e = m - 1;
        else
        {
            ans = m;
            s = m + 1;
        }
    }

    // finding decimal part
    float factor = 0.1;
    for (int i = 1; i <= p; i++)
    {
        while (ans * ans <= x)
            ans += factor;

        ans -= factor;
        factor /= 10.0;
    }

    return ans;
}

int main()
{
    float x;
    int p;
    cout << "Enter number and precision: ";
    cin >> x >> p;
    cout << findSqrt(x, p) << endl;
}