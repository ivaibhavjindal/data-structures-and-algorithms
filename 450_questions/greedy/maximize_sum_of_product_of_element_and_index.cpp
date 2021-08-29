// https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1

class Solution
{
public:
    int Maximize(int a[], int n)
    {
        sort(a, a + n);

        long long mod = pow(10, 9) + 7;
        long long ans = 0, i = 0;

        for (; i < n; i++)
            ans += (a[i] * i);

        ans %= mod;

        return ans;
    }
};
