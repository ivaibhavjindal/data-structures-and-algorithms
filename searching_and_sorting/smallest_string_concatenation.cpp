// https://www.geeksforgeeks.org/lexicographically-smallest-string-obtained-concatenating-array/

#include <bits/stdc++.h>
using namespace std;

bool compare(string x, string y)
{
    return x + y < y + x;
}

void concatLexicographically(vector<string> v)
{
    sort(v.begin(), v.end(), compare);

    for (auto x : v)
        cout << x;
    cout << endl;
}

int main()
{
    vector<string> arr = {"a", "ab", "aba"};
    concatLexicographically(arr);
}