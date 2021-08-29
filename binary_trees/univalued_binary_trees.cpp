// https://leetcode.com/problems/univalued-binary-tree/

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
    bool isUnival(TreeNode *root, int val)
    {
        if (root == NULL)
            return true;

        if (root->val != val)
            return false;

        return isUnival(root->left, val) && isUnival(root->right, val);
    }

    bool isUnivalTree(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return isUnival(root, root->val);
    }
};