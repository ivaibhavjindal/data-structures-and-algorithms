// https://leetcode.com/problems/majority-element/

// Boyer-Moore Majority Vote Algorithm
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = nums[0], count = 1, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == major)
                count++;
            else if (count == 0)
            {
                major = nums[i];
                count = 1;
            }
            else
                count--;
        }

        return major;
    }
};