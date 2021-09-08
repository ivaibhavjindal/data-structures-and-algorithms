// https://leetcode.com/problems/fibonacci-number/

class Solution
{
public:
    int topDown(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return n;

        if (dp[n] != 0)
            return dp[n];

        return dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);
    }

    int bottomUp(int n)
    {
        int a = 0, b = 1, c;
        if (n == 0)
            return a;
        else if (n == 1)
            return b;

        for (int i = 0; i <= n - 2; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }

    int fib(int n)
    {
        return bottomUp(n);

        vector<int> dp(n + 1, 0);
        return topDown(n, dp);
    }
};