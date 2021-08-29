// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    bool isSame(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        return (root1->val == root2->val) && isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        // base case
        if (cloned == NULL)
            return cloned;

        // if node found [isSame handles multiple nodes with same value]
        if (original->val == target->val && isSame(target, cloned))
            return cloned;

        // check recursively for left and right children
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        TreeNode *right = getTargetCopy(original->right, cloned->right, target);

        // if at left
        if (left)
            return left;
        // if at right or not available
        return right;
    }
};