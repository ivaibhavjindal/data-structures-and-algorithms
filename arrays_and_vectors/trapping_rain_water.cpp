// https://leetcode.com/problems/trapping-rain-water/

class Solution
{
public:
    // O(N)
    int trap(vector<int> &height)
    {
        int ans = 0, cur_max = 0, n = height.size();
        vector<int> left(n), right(n);

        // left max
        for (int i = 0; i < n; i++)
        {
            left[i] = cur_max;
            cur_max = max(height[i], cur_max);
        }

        // right max
        cur_max = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = cur_max;
            cur_max = max(height[i], cur_max);
        }
        for (int i = 0; i < n; i++)
            if (min(left[i], right[i]) > height[i])
                ans += min(left[i], right[i]) - height[i];

        return ans;
    }
};