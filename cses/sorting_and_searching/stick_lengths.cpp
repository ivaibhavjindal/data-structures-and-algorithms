#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    int n;
    ll ans = 0; 
    cin >> n;

    vector<ll> v(n);
    for(auto &x: v)
        cin >> x;
    
    sort(v.begin(), v.end());

    for(auto x: v) 
        ans += abs(x-v[n/2]);
 
    cout << ans << endl;
}
