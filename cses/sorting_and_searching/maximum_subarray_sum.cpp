#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for(auto &x: arr)
        cin >> x;

    ll cur_sum = 0, max_sum = 0, max_val = arr[0];
    for(int i = 0; i < n; i++) {
        max_val = max(max_val, (ll)arr[i]);
        cur_sum = max(0ll, cur_sum+arr[i]);
        max_sum = max(max_sum, cur_sum);
    }
    cout << (max_val >= 0 ? max_sum : max_val)  << endl;

}
