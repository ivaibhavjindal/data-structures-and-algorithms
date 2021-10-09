// https://leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;

        // product of all integers on left
        for (int left = 1; left < n; left++)
            ans[left] = nums[left - 1] * ans[left - 1];

        // product of all integers on right
        int right_product = nums[n - 1];
        for (int right = n - 2; right >= 0; right--)
        {
            ans[right] = ans[right] * right_product;
            right_product *= nums[right];
        }

        return ans;
    }
};