// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int bottomUp(vector<int> &arr)
    {
        int ans = 1;
        int n = arr.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        return bottomUp(nums);
    }
};