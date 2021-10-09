#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

const int sz = 1e5;

int main() {
    int n, l, r, max_val = 0;
    cin >> n;
    int arr1[sz+1] = {0}, arr2[sz] = {0};
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        l < sz ? arr1[l] = 1 : arr2[l-sz] = 1;
        r < sz ? arr1[r+1] = -1 : arr2[r-sz+1] = -1;
    }

    for(int i = 1; i <= sz; i++) {
        arr1[i] += arr1[i-1];
    } arr2[0] = arr1[sz];
    for(int i = 1; i < sz; i++) {
        arr2[i] += arr2[i-1];
    }
    for(int i = 0; i <= sz; i++)
        max_val = max(max_val, arr1[i]);
    for(int i = 0; i < sz; i++)
        max_val = max(max_val, arr2[i]);

    cout << max_val << endl;    
}
