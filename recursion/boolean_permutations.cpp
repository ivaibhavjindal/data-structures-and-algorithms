#include <bits/stdc++.h>
using namespace std;

void boolean_permutation(int n, vector<bool> v)
{
    if (n == 0)
    {
        for (auto x : v)
            cout << (x ? "T" : "F") << " ";
        cout << endl;
    }
    else
    {
        vector<bool> t1 = v, t2 = v;
        t1.push_back(false);
        t2.push_back(true);
        boolean_permutation(n - 1, t1);
        boolean_permutation(n - 1, t2);
    }
}

int main()
{
    vector<bool> vec;
    int n;
    cout << "Enter number of boolean variables: ";
    cin >> n;
    boolean_permutation(n, vec);
}
