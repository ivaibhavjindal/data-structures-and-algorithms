// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution
{
public:
    bool outOfOrder(vector<int> &nums, int ind)
    {
        if (ind == 0)
            return nums[ind] > nums[1];

        if (ind == nums.size() - 1)
            return nums[ind] < nums[ind - 1];

        return (nums[ind] < nums[ind - 1]) || (nums[ind] > nums[ind + 1]);
    }

    // O(N)
    int findUnsortedSubarray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int smallest = INT_MAX, largest = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (outOfOrder(nums, i))
            {
                largest = max(largest, nums[i]);
                smallest = min(smallest, nums[i]);
            }
        }
        int l, r;
        for (l = 0; l < nums.size() && nums[l] <= smallest; l++)
            ;
        for (r = nums.size() - 1; r >= 0 && nums[r] >= largest; r--)
            ;

        return r - l < 0 ? 0 : r - l + 1;
    }
};

// Another approach can be using sorting, sort and find the first diff elem from
// left(ind = l) and right(ind = r) => ans = (r-l+1) O(N*log(N))
int NlogN(vector<int> &nums)
{
    int n = nums.size();
    vector<int> orig(n);
    for (int i = 0; i < n; i++)
        orig[i] = nums[i];

    sort(nums.begin(), nums.end());

    int l = 0, r = n - 1;
    while (l < n && nums[l] == orig[l])
        l++;

    if (l == n)
        return 0;

    while (r >= 0 && nums[r] == orig[r])
        r--;

    return r - l + 1;
}