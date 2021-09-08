// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxsum = nums[0], cursum = 0;
        for (int i = 0; i < n; i++)
        {
            cursum = max(cursum + nums[i], nums[i]);
            maxsum = max(cursum, maxsum);
        }

        return maxsum;
    }
};