// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

int bottomUp(vector<int> arr, int n)
{
    vector<int> dp(n, 0);
    dp[n - 2] = abs(arr[n - 2] - arr[n - 1]);

    for (int i = n - 3; i >= 0; i--)
    {
        int cost_jump_1 = abs(arr[i] - arr[i + 1]) + dp[i + 1];
        int cost_jump_2 = abs(arr[i] - arr[i + 2]) + dp[i + 2];
        dp[i] = min(cost_jump_1, cost_jump_2);
    }

    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    cout << bottomUp(arr, n) << endl;
}