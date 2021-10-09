#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll n, mod = 1e9+7;
    cin >> n;
    ll ans = 1;
    while(n--) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl; 
}
