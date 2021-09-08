// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution
{
public:
    int topDown(int n, int x, int y, int z, vector<int> &dp)
    {
        if (n < 0)
            return INT_MIN;

        if (n <= 0)
            return 0;

        if (dp[n] != 0)
            return dp[n];

        dp[n] = 1 + max(max(topDown(n - x, x, y, z, dp), topDown(n - y, x, y, z, dp)), topDown(n - z, x, y, z, dp));

        return dp[n];
    }

    int bottomUp(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i >= x)
                dp[i] = max(dp[i], dp[i - x]);

            if (i >= y)
                dp[i] = max(dp[i], dp[i - y]);

            if (i >= z)
                dp[i] = max(dp[i], dp[i - z]);

            if (dp[i] != -1)
                dp[i] += 1;
        }

        return (dp[n] == -1 ? 0 : dp[n]);
    }

    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {

        return bottomUp(n, x, y, z);

        vector<int> dp(n + 1, 0);
        int ans = topDown(n, x, y, z, dp);
        return max(ans, 0);
    }
};
