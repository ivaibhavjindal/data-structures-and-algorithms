// https://leetcode.com/problems/coin-change/

class Solution
{
public:
    int topDown(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount < 0)
            return INT_MAX;

        if (amount == 0)
            return 0;

        if (dp[amount] != INT_MAX)
            return dp[amount];

        int k = coins.size();
        dp[amount] = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            int min_coins = topDown(coins, amount - coins[i], dp);
            if (min_coins != INT_MAX)
                dp[amount] = min(dp[amount], 1 + min_coins);
        }

        return dp[amount];
    }

    int bottomUp(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0);

        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            for (auto c : coins)
                if (i - c >= 0 && dp[i - c] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - c]);
        }

        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        return bottomUp(coins, amount);

        vector<int> dp(amount + 1, INT_MAX);
        int min_coins = topDown(coins, amount, dp);
        return (min_coins == INT_MAX ? -1 : min_coins);
    }
};