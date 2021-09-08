// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int bottomUp(vector<int> arr, int n, int k)
{
    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = INT_MAX;
        for (int j = i + 1; ((j < n) && (j <= i + k)); j++)
        {
            dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
        }
    }

    return dp[0];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    cout << bottomUp(arr, n, k) << endl;
}