#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    
    vector <string> v;
    do {
        v.push_back(s);
    } while(next_permutation(begin(s), end(s)));

    cout << v.size() << endl;
    for(auto x: v)
        cout << x << endl;
}
