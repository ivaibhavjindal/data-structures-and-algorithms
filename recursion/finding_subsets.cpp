// https://leetcode.com/problems/subsets/

class Solution
{
public:
    void genSubset(vector<int> &nums, vector<int> subset, int i, set<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.insert(subset);
            return;
        }

        genSubset(nums, subset, i + 1, ans);
        subset.push_back(nums[i]);
        genSubset(nums, subset, i + 1, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> v;
        genSubset(nums, v, 0, s);
        for (auto x : s)
            ans.push_back(x);
        return ans;
    }
};