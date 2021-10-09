#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

ll trailingZeros(ll n) {
    ll zeros = 0, multiple_of_5 = 5;
    
    while(multiple_of_5 <= n) {
        zeros += n / multiple_of_5 ;
        multiple_of_5 *= 5;
    }

    return zeros;
}

int main() {
    ll n;
    cin >> n;
    cout << trailingZeros(n) << endl;
}
