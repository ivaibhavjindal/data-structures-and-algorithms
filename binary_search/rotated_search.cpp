// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    // O(log(N))
    int rotatedSearch(vector<int> &arr, int l, int r, int key)
    {
        if (l > r)
            return -1;

        int m = (l + r) / 2;

        // (line 1)  (line 2)
        // 4,5,6,7,   0,1,2
        if (arr[m] == key)
            return m;
        // mid point on line1
        else if (arr[m] >= arr[l])
        {
            if (key >= arr[l] && key < arr[m]) // left half of line1
                return rotatedSearch(arr, l, m - 1, key);
            else
                return rotatedSearch(arr, m + 1, r, key);
        }
        // mid point on line 2
        else if (arr[m] <= arr[r])
        {
            if (key > arr[m] && key <= arr[r]) // right half of line2
                return rotatedSearch(arr, m + 1, r, key);
            else
                return rotatedSearch(arr, l, m - 1, key);
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        return rotatedSearch(nums, 0, nums.size() - 1, target);
    }
};