// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    // traverse inorder => sorted check diff b/w cur and prev node
    void inorderMinDif(TreeNode *root, int *prev, int *ans)
    {
        if (root != NULL)
        {
            inorderMinDif(root->left, prev, ans);

            if (*prev != -1)
                *ans = min(*ans, abs(root->val - *prev));
            *prev = root->val;

            inorderMinDif(root->right, prev, ans);
        }
    }

    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        int prev = -1;
        inorderMinDif(root, &prev, &ans);

        return ans;
    }

    int minDiffInBST(TreeNode *root)
    {
        return getMinimumDifference(root);
    }
};