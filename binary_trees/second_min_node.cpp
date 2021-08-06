// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    int secondMin(TreeNode *root, int minval)
    {
        // base case
        if (root == NULL)
            return -1;

        // second minimum
        if (root->val != minval)
            return root->val;

        // recursively find second min from left and right subtree
        int left = secondMin(root->left, minval);
        int right = secondMin(root->right, minval);

        // if found in only left or only right subtree return that else return min of both
        if (left != -1 && right == -1)
            return left;
        else if (left == -1 && right != -1)
            return right;
        else
            return min(left, right);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        return secondMin(root, root->val);
    }
};