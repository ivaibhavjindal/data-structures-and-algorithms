// number of subsets having given sum

#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> v, int i, int x)
{
    if (i == v.size())
    {
        if (x == 0)
            return 1;
        else
            return 0;
    }

    return subsetSum(v, i + 1, x - v[i]) + subsetSum(v, i + 1, x);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int key = 6;
    cout << subsetSum(v, 0, key) << endl;
}