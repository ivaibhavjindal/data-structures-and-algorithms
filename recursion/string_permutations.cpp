#include <bits/stdc++.h>
using namespace std;

void permutation(string s, int l, int h)
{
    if (l == h)
        cout << s << endl;
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            permutation(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int l = 0, h = s.length() - 1;
    cout << "Permutations\n";
    permutation(s, l, h);
}
