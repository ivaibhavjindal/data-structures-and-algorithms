#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

void towerOfHanoi(int n, int src, int dest, int aux) {
    if(n == 1) {
        cout << src << " " << dest << endl;
    } else {
        towerOfHanoi(n-1, src, aux, dest);
        towerOfHanoi(1, src, dest, aux);
        towerOfHanoi(n-1, aux, dest, src);
    }
}

int main() {
   int n;
   cin >> n; 
   ll moves = (ll)((1<<n)-1); 
   cout << moves << endl;
   towerOfHanoi(n, 1, 3, 2);
}