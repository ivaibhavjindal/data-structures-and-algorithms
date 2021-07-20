#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// print all subsets/subsequences sorted by length
// and for same length by lexicographic order

// recursion (O(2^N))
void genSubsets(string s, string o, vector<string> &v)
{
    // base case
    if (s.size() == 0)
    {
        v.push_back(o);
        return;
    }

    // remove first character
    char ch = s[0];
    string reduced_input = s.substr(1);

    // include character
    genSubsets(reduced_input, o + ch, v);
    // not include character
    genSubsets(reduced_input, o, v);
}

bool compare(string s1, string s2)
{
    // lexicographic for same length
    if (s1.length() == s2.length())
        return s1 < s2;

    // else lengthwise
    return s1.length() < s2.length();
}

int main()
{
    string s, output = "";
    cin >> s;
    vector<string> v;
    genSubsets(s, output, v);
    sort(v.begin(), v.end(), compare);
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}