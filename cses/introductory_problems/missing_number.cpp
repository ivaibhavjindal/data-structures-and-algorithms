#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll n, x, cur_sum = 0;
    cin >> n;
    ll first_n_sum = (n * (n+1)) / 2;
    while(--n) {   
        cin >> x;
        cur_sum += x;
    } 
    cout << first_n_sum - cur_sum << endl;
}