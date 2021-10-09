#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int longestUniqueSequence(vector<int> arr)
{
    map<int, int> mp;
    int i = 0, n = arr.size(), ans = 1;
    for (int j = 0; j < n; j++)
    {
        if (mp.find(arr[j]) != mp.end() && mp[arr[j]] >= i)
            i = mp[arr[j]] + 1;

        mp[arr[j]] = j;

        ans = max(ans, j - i + 1);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    cout << longestUniqueSequence(v) << endl;
}