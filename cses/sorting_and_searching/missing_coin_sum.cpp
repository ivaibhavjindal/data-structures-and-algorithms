#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll min_sum = 1, n;
    cin >> n;

    vector<ll> v(n);
    for(auto &x: v)
        cin >> x;
    
    sort(v.begin(), v.end());

    for(int i = 0; (i < n) && (v[i] <= min_sum); i++)
        min_sum += v[i];
 
    cout << min_sum << endl;
}
