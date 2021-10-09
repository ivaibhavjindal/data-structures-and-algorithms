#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 2 || n == 3)
        cout << "NO SOLUTION\n";
    else {
        int k = n;
        if((k & 1) == 0) // even 
            k--;
        while(k > 0) {
            cout << k << " ";
            k -= 2;
        }

        k = n;
        if(k & 1) // odd
            k--;
        while(k > 0) {
            cout << k << " "; 
            k -= 2;
        }
    }
}
