#include <bits/stdc++.h>
using namespace std;
 
void grayCode(int n) {
    for(int i = 0; i < (1 << n); i++) {
        int gray = (i ^ (i >> 1)); // binary to gray
        // cout << "i: " << i << " i >> 1: " << (i >> 1) << " gray: " << gray << endl;
        // binary to decimal
        string bin_val = bitset<32> (gray).to_string();
        cout << bin_val.substr(32 - n) << endl;
    }
}

int main() {
    int n;
    cin >> n;
    grayCode(n);
}
