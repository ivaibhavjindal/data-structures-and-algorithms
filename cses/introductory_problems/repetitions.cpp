#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    int final_ans = 1, cur_ans = 1;
    string s;
    cin >> s;
    for(int i = 1; s[i]; i++) {
        if(s[i] == s[i-1])
            cur_ans++;
        else {
            final_ans = max(cur_ans, final_ans);
            cur_ans = 1;
        }
    } 
    cout << max(final_ans, cur_ans) << endl;
}