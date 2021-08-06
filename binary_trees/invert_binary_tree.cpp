// https://leetcode.com/problems/invert-binary-tree/

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
    void invert(TreeNode *root)
    {
        if (root == NULL)
            return;

        // recursive call on left and right subtree
        invert(root->left);
        invert(root->right);
        // swap left and right child
        swap(root->left, root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};