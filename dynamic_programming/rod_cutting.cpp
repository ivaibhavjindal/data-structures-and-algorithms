// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

#include <bits/stdc++.h>
using namespace std;

int topDown(int prices[], int n, vector<int> &dp)
{
    if (n <= 0)
        return 0;

    if (dp[n] != 0)
        return dp[n];

    dp[n] = INT_MIN;
    // cut lengths => 1 to n
    for (int i = 0; i < n; i++)
        dp[n] = max(dp[n], prices[i] + topDown(prices, n - (i + 1), dp));

    return dp[n];
}

int bottomUp(int prices[], int n)
{
    vector<int> dp(n + 1, 0);

    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i < len; i++)
        {
            if (len - (i + 1) >= 0)
                dp[len] = max(dp[len], prices[i] + dp[len - (i + 1)]);
        }
    }

    return dp[n];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);
    vector<int> dp(n + 1, 0);

    cout << bottomUp(prices, n) << endl;

    cout << topDown(prices, n, dp) << endl;
}