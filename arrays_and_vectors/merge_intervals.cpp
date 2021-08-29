// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();
        
        for(int i = 1; i < n; i++) {
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            
            if(end >= cur_start)
                end = max(cur_end, end);
            else {
                ans.push_back({start, end});
                start = cur_start;
                end = cur_end;
            }
        }
        
        n = ans.size();
        cout << n << endl;
        if(ans.empty() || (ans[n-1][0] != start && ans[n-1][1] != end))
            ans.push_back({start, end});
        
        return ans;
    }
};