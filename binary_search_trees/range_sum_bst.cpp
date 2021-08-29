// https://leetcode.com/problems/range-sum-of-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void rangeSum(TreeNode *root, int l, int r, int *ans)
    {
        //base case
        if (root == NULL)
            return;

        // update ans
        if (root->val >= l && root->val <= r)
            *ans += root->val;

        // if less than range go to right
        if (root->val < l)
            rangeSum(root->right, l, r, ans);
        // if more than range go to left
        else if (root->val > r)
            rangeSum(root->left, l, r, ans);
        // if in range go both left and right
        else
        {
            rangeSum(root->left, l, r, ans);
            rangeSum(root->right, l, r, ans);
        }
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        rangeSum(root, low, high, &ans);

        return ans;
    }
};