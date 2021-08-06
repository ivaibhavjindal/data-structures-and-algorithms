// https://leetcode.com/problems/binary-tree-tilt/

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
    int updateTilt(TreeNode *root, int *tilt)
    {
        // base case
        if (root == NULL)
            return 0;

        // update tilt and return sum of left subtree
        int left = updateTilt(root->left, tilt);
        // update tilt and return sum of right subtree
        int right = updateTilt(root->right, tilt);

        // update tilt
        *tilt += abs(left - right);
        // return sum
        return root->val + left + right;
    }

    int findTilt(TreeNode *root)
    {
        int tilt = 0;
        updateTilt(root, &tilt);
        return tilt;
    }
};