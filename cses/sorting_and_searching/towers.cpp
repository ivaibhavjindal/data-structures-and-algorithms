#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int towers(vector<int> arr)
{
    int n = arr.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({arr[i], i});

    sort(v.rbegin(), v.rend());

    int min_towers = 1, cur_pos = -1;
    for (auto x : v)
    {
        if (x.second < cur_pos)
            min_towers++;

        cur_pos = x.second;
    }

    return min_towers;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    cout << towers(arr);
}

10

10 10 9 7
 1  6 4  
10 4 5 9 4 10 2 7 4 6