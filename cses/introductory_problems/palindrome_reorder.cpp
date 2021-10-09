#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    int arr[26] = {0};
    string s;
    cin >> s;
    for(auto x: s)
        arr[x-'A']++;
    int odd = 0, odd_index = -1;
    for(int i = 0; i < 26; i++) {
        if(arr[i]) {
            if(arr[i] & 1) {
                odd++;
                odd_index = i;
            }
        }
    }
    if(odd > 1)
        cout << "NO SOLUTION\n";
    else {
        string ans;
        for(int i = 0; i < 26; i++)
            if(i != odd_index)
                for(int j = 0; j < arr[i]/2; j++)
                    ans += (char)('A' + i);

        if(odd_index != -1)
            for(int j = 0; j < arr[odd_index]; j++)
                ans += (char)('A' + odd_index);
       
        for(int i = 25; i >= 0; i--)
             if(i != odd_index)
                for(int j = 0; j < arr[i]/2; j++)
                    ans += (char)('A' + i);

        cout << ans << endl;
    }
}
