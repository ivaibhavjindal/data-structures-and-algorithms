// https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    vector<vector<int>> bottomUp(int n)
    {
        vector<vector<int>> dp(n);
        dp[0].push_back(1);

        for (int i = 1; i < n; i++)
        {
            dp[i].push_back(1);

            for (int col = 0; col < i - 1; col++)
                dp[i].push_back(dp[i - 1][col] + dp[i - 1][col + 1]);

            dp[i].push_back(1);
        }

        return dp;
    }
    vector<vector<int>> generate(int numRows)
    {
        return bottomUp(numRows);
    }
};