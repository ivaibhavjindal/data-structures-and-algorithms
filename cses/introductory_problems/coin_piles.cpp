#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

bool coinPiles(int a, int b) {
    int x = ((2*b) - a)/3;
    int y = ((2*a) - b)/3;
    if(x < 0 || y < 0)
        return false;
    return (((x + 2*y) == a) && ((y + 2*x) == b));
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int a, b;
        cin >> a >> b;
        cout << (coinPiles(a, b) ? "YES\n" : "NO\n");
    }
}
