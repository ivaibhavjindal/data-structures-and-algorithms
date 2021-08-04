// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
    // O(log(N))
    int firstOccurence(vector<int> &nums, int l, int r, int key, int ans)
    {
        if (l > r)
            return ans;

        int m = (l + r) / 2;
        if (nums[m] == key)
        {
            ans = m;
            // continue search in left half
            return firstOccurence(nums, l, m - 1, key, ans);
        }
        else if (nums[m] > key)
            return firstOccurence(nums, l, m - 1, key, ans);
        else
            return firstOccurence(nums, m + 1, r, key, ans);
    }

    // O(log(N))
    int lastOccurence(vector<int> &nums, int l, int r, int key, int ans)
    {
        if (l > r)
            return ans;

        int m = (l + r) / 2;
        if (nums[m] == key)
        {
            ans = m;
            // continue search in right half
            return lastOccurence(nums, m + 1, r, key, ans);
        }
        else if (nums[m] > key)
            return lastOccurence(nums, l, m - 1, key, ans);
        else
            return lastOccurence(nums, m + 1, r, key, ans);
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int fo = firstOccurence(nums, 0, nums.size() - 1, target, -1);
        int lo = lastOccurence(nums, 0, nums.size() - 1, target, -1);
        vector<int> v = {fo, lo};
        return v;
    }
};