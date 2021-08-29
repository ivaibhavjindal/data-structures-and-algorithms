// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    // early stopping of inorder traversal of bst (sorted array)
    void kthSmallestInorder(TreeNode *root, int k, int *cur, int *ans)
    {
        if (root != NULL)
        {
            kthSmallestInorder(root->left, k, cur, ans);

            *cur += 1;
            if (k == *cur)
                *ans = root->val;

            kthSmallestInorder(root->right, k, cur, ans);
        }
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int cur = 0, ans = 0;
        kthSmallestInorder(root, k, &cur, &ans);
        return ans;
    }
};