// https://leetcode.com/problems/path-sum/

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
    bool path(TreeNode *root, int targetSum, int curSum)
    {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
        {
            if (targetSum - curSum == root->val)
                return true;
            return false;
        }

        return path(root->left, targetSum, curSum + root->val) || path(root->right, targetSum, curSum + root->val);
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return path(root, targetSum, 0);
    }
};