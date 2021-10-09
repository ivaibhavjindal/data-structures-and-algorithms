#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n";
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <pair<int, int>> movies(n);
    for(auto &m: movies)
        cin >> m.second >> m.first;

    // sort non-decreasing order of ending times
    sort(movies.begin(), movies.end());
    
    int ans = 1, prev_finish_time = movies[0].first;
    for(int i = 1; i < n; i++) {
        int cur_start_time = movies[i].second;
        int cur_end_time = movies[i].first;

        if(cur_start_time >= prev_finish_time) {
            ans++;
            prev_finish_time = cur_end_time;
        }
    }
    cout << ans << endl;
}
