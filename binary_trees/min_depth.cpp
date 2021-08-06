// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ld = INT_MAX, rd = INT_MAX;

        // left child exist
        if (root->left)
            ld = minDepth(root->left);

        // right child exist
        if (root->right)
            rd = minDepth(root->right);

        // both left and right child does not exist
        if (root->left == NULL && root->right == NULL)
            ld = rd = 0;

        return 1 + min(ld, rd);
    }
};