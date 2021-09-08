// https://leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    // k = 2 => jump of steps (1 or 2) [top down]
    int climb(int n, int k, vector<int> &dp)
    {
        if (n < 0)
            return 0;

        if (n == 0)
            return 1;

        if (dp[n] != 0)
            return dp[n];

        // optimisation(instead of for loop): dp[n] = 2 * dp[n-1] - dp[n-k-1]
        for (int i = 1; i <= k; i++)
            dp[n] += climb(n - i, k, dp);

        return dp[n];
    }

    // bottom up
    int climbIterative(int n, int k)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                    dp[i] += dp[i - j];
            }
        }

        return dp[n];
    }

    int climbStairs(int n)
    {
        // bottom up
        return climbIterative(n, 2);

        // top down
        vector<int> dp(n + 1, 0);
        return climb(n, 2, dp);
    }
};