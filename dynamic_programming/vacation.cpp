// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int bottomUp(vector<vector<int>> arr, int n)
{
    vector<int> dp(n, 0);
    dp[n - 1] = max(arr[n - 1][0], max(arr[n - 1][1], arr[n - 1][2]));
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = INT_MIN;
        if (dp[i] < arr[i][0] && dp[i + 1] != arr[i + 1][0])
            dp[i] = arr[i][0];
        if (dp[i] < arr[i][1] && dp[i + 1] != arr[i + 1][1])
            dp[i] = arr[i][1];
        if (dp[i] < arr[i][2] && dp[i + 1] != arr[i + 1][2])
            dp[i] = arr[i][2];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += dp[i];
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int a, b, c;
    vector<vector<int>> v(n);
    for (auto &x : v)
    {
        cin >> a >> b >> c;
        x.push_back(a);
        x.push_back(b);
        x.push_back(c);
    }

    cout << bottomUp(v, n) << endl;
}