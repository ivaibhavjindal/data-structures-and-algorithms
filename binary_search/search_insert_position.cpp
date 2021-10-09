// https://leetcode.com/problems/search-insert-position/

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int ans = end - (end - start) / 2;

        if (nums[0] > target)
            return 0;
        else if (nums[end] < target)
            return end + 1;

        while (start <= end)
        {
            int mid = end - (end - start) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        return ans + 1;
    }
};