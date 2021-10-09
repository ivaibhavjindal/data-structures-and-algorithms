// https://leetcode.com/problems/permutations/

class Solution
{
public:
    void permutations(vector<int> nums, vector<vector<int>> &ans, int l, int h)
    {
        if (l == h)
            ans.push_back(nums);
        else
        {
            for (int i = l; i <= h; i++)
            {
                swap(nums[i], nums[l]);
                permutations(nums, ans, l + 1, h);
                swap(nums[i], nums[l]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permutations(nums, ans, 0, nums.size() - 1);
        return ans;
    }
};