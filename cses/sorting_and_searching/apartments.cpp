#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector <ll> req(n), apartments(m);
    for(auto &x: req)
        cin >> x;
    for(auto &x: apartments)
        cin >> x;

    // sort non-decreasing order
    sort(req.begin(), req.end());
    sort(apartments.begin(), apartments.end());
    
    int i = 0, j = 0;
    while(i < n && j < m) {
        // suitable apartment
        if((req[i] + k >= apartments[j]) 
            && (req[i] - k <= apartments[j])) {
                i++; // next applicant
                j++; // next apartment
                ans++;
            }
        // apartment bigger than required
        else if (apartments[j] > req[i]+k) {
            i++; // next applicant
        } 
        // apartment smaller than required
        else {
            j++; // next apartment
        }
    }
    cout << ans << endl;
}
