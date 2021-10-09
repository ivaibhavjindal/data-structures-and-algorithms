#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sumOfThreeValues(vector<long long> v, int key)
{
    int n = v.size();
    vector<pair<long long, int>> vp;
    for (int i = 0; i < n; i++)
        vp.push_back({v[i], i + 1});

    sort(vp.begin(), vp.end());

    for (int i = 0; i < n - 2; i++)
    {
        int req_sum = key - vp[i].first;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int pair_sum = vp[j].first + vp[k].first;

            if (pair_sum == req_sum)
            {
                cout << vp[i].second << " " << vp[j].second << " " << vp[k].second << endl;
                return;
            }
            else if (pair_sum > req_sum)
                k--;
            else
                j++;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (auto &x : v)
        cin >> x;

    sumOfThreeValues(v, x);
}