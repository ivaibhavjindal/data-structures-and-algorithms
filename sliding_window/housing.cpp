// buying empty plots (https://www.iarcs.org.in/inoi/online-study-material/topics/sliding-window-one-empty-plot.php)

// Along one side of a road there is a sequence of vacant plots of land. Each plot has a different area (non-zero).
// So, the areas form a sequence A[1], A[2], … A[N].

// You want to buy K acres of land to build a house.
// You want to find a segment of continguous plots (i.e., a subsection in the sequence)
// of minimum length whose sum is exactly K.

#include <iostream>
#include <vector>

using namespace std;

// O(N)
vector<pair<int, int>> findPlots(vector<int> area, int k)
{
    int i = 0, j = 0, n = area.size(), cur_window_sum = 0;
    vector<pair<int, int>> ans;

    // while window sum < k => expand window
    for (j = 0; j < n; j++)
    {
        cur_window_sum += area[j];

        if (cur_window_sum == k)
            ans.push_back({i, j});

        else if (cur_window_sum > k)
        {
            // while window sum > k => contract window
            while (cur_window_sum > k and i < j)
            {
                cur_window_sum -= area[i];
                i++;
            }
            if (cur_window_sum == k)
                ans.push_back({i, j});
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> area(n);
    for (auto &x : area)
        cin >> x;

    vector<pair<int, int>> vp = findPlots(area, k);
    for (auto x : vp)
        cout << x.first << " " << x.second << endl;
}