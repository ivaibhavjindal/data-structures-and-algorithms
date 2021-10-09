#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    ll n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        
        if(n&1) // odd
            n = n*3 + 1;
        else // even
            n /= 2;
    } 
    cout << n << endl;
}