#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll n, x;
    set <ll> s;
    cin >> n;
    while(n--) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
 
}
