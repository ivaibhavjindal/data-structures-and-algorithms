// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> v(n); // v[i] = max value from i to n-1
        v[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--)
            v[i] = max(prices[i], v[i + 1]);

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans = max(ans, v[i + 1] - prices[i]);

        return ans;
    }
};