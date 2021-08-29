// https://leetcode.com/problems/sum-of-left-leaves/

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
    void leftSum(TreeNode *root, TreeNode *par, int *ans)
    {
        // base case
        if (root == NULL)
            return;

        // leaf nodes
        if (par != NULL && root->left == NULL && root->right == NULL)
        {
            // left child
            if (root == par->left)
                *ans += root->val;
            return;
        }

        // update parent
        par = root;

        //recursive calls
        leftSum(root->left, root, ans);
        leftSum(root->right, root, ans);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;
        leftSum(root, NULL, &ans);
        return ans;
    }
};