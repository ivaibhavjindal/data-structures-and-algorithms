#include <bits/stdc++.h>
using namespace std;

// Sort two columns of string pairwise
// Given the column on which to sort
// If output should be reversed
// If sort by number or lexicographic

/* Sample Input
Input
------
3
92 022
82 12
77 13
2 false numeric

Output
-------
82 12
77 13
92 022
*/

// extract string at 'key' position from
//a line of strings separated by space
string extractStringAtKey(string str, int key)
{
    // convert string to char array for strtok input
    char *s = strtok((char *)str.c_str(), " ");
    while (--key)
        s = strtok(NULL, " ");

    // typecast char array back to string
    return (string)s;
}

int convertToInt(string s)
{
    int ans = 0, power = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ans += ((s[i]) - '0') * power;
        power *= 10;
    }

    return ans;
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return key1 < key2;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

int main()
{
    int n;
    cin >> n;
    cin.get();

    string temp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // extract keys for comparision and store items
    vector<pair<string, string>> vp;
    for (auto x : v)
        vp.push_back({x, extractStringAtKey(x, key)});

    // sorting
    if (ordering == "numeric")
        sort(vp.begin(), vp.end(), numericCompare);
    else
        sort(vp.begin(), vp.end(), lexicoCompare);

    // reversal
    if (reversal == "true")
        reverse(vp.begin(), vp.end());

    //output
    for (auto x : vp)
        cout << x.first << endl;
}