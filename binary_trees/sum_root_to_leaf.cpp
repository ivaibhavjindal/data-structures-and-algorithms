// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void sumPath(TreeNode *root, int cursum, int *ans)
    {
        // base case
        if (root == NULL)
            return;

        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            *ans += (cursum * 10 + root->val);
            return;
        }

        // recursive calls on left and right subtree
        sumPath(root->left, cursum * 10 + root->val, ans);
        sumPath(root->right, cursum * 10 + root->val, ans);
    }

    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        sumPath(root, 0, &ans);
        return ans;
    }
};
