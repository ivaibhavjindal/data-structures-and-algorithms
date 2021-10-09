#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

const int mod = 1e9+7;

int coinPiles(int n, int coin_piles[]) {
    if(n == 0)
        return 1;
   
    if(coin_piles[n] != -1)
        return coin_piles[n];
    
    int count = 0;
    for(int i = 1; i <= 6; i++) {
        if(n-i >= 0) {
            count += coinPiles(n-i, coin_piles);
            count %= mod;
        }
    }  
    return coin_piles[n] = count;
}

int main() {
    int n;
    cin >> n;

    int dp[n+1];
    memset(dp, -1, sizeof(dp));

    cout << coinPiles(n, dp) << endl;
}
