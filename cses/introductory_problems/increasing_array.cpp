#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll ans = 0, prev, cur;
    int n;
    cin >> n >> prev;
    while(--n) {
        cin >> cur;

        if(cur < prev) {
            ans += (prev-cur);
            cur = prev;
        }

        prev = cur;
    }
    cout << ans << endl;
}