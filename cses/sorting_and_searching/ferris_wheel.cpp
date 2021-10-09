#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll n, x, ans = 0;
    cin >> n >> x;
    vector <ll> weights(n);
    for(auto &w: weights)
        cin >> w;

    // sort non-decreasing order
    sort(weights.begin(), weights.end());
    
    int i = 0, j = n-1;
    while(i <= j) {
        // if lightest and heaviest can sit together
        if(weights[j] + weights[i] <= x) {
            i++; 
            j--; 
            ans++;
        } 
        // heaviest sits alone
        else {
            j--;
            ans++;
        }
    }
    cout << ans << endl;
}
