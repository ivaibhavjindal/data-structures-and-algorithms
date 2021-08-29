// https://leetcode.com/problems/subtree-of-another-tree/

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
    bool isSame(TreeNode *root1, TreeNode *root2)
    {
        // base cases
        if (root1 == NULL && root2 == NULL)
            return true;

        else if (root1 == NULL || root2 == NULL)
            return false;

        // recursively check
        return (root1->val == root2->val) && isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // base cases
        if (subRoot == NULL && root == NULL)
            return true;
        if (subRoot == NULL || root == NULL)
            return false;

        // check for same trees
        if (isSame(root, subRoot))
            return true;

        // recursively check for left and right children
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};