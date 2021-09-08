// https://leetcode.com/problems/jump-game-ii/

class Solution
{
public:
    int bottomUp(vector<int> arr, int n)
    {
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = INT_MAX;
            for (int j = i + 1; j <= (i + arr[i]) && j < n; j++)
            {
                if (dp[j] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[j]);
            }
        }

        return (dp[0] == INT_MAX ? -1 : dp[0]);
    }

    int jump(vector<int> &nums)
    {
        return bottomUp(nums, nums.size());
    }
};