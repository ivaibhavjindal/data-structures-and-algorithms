#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

const int mod = 1e9+7;

int minimizeCoins(int num_coins, int sum, int coins[], int dp[]) {
    if(sum == 0)
        return 1    ;
   
    if(dp[sum] != -1)
        return dp[sum];
    
    int count = 0;
    for(int i = 0; i < num_coins; i++) {
        if(sum-coins[i] >= 0) {
            count += minimizeCoins(num_coins, sum-coins[i], coins, dp);
        }
    }  
    return dp[sum] = count;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    int dp[x+1], coins[n];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    cout << minimizeCoins(n, x, coins, dp) << endl;
}
