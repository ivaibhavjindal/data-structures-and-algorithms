// https://www.geeksforgeeks.org/count-total-anagram-substrings/

#include <bits/stdc++.h>
using namespace std;

int countAnagrams(string s)
{
    int n = s.size();
    map<vector<int>, int> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> v(26, 0);
            for (int k = i; k <= j; k++)
                v[s[k] - 'a']++;

            mp[v]++;
        }
    }

    int ans = 0;
    for (auto p : mp)
        ans += (p.second * (p.second - 1)) / 2;

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << countAnagrams(s) << endl;
}