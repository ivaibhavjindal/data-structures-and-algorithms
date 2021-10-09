#include <iostream>
#include <vector>
using namespace std;

int subArraySums(vector<long long> v, int key)
{
    int i = 0, n = v.size();
    long long cur_window_sum = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        cur_window_sum += v[j];

        while (i <= j && cur_window_sum > key)
            cur_window_sum -= v[i++];

        if (cur_window_sum == key)
            ans++;
    }

    return ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (auto &k : v)
        cin >> k;

    cout << subArraySums(v, x) << endl;
}