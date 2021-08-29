// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    void greaterTree(TreeNode *root, int *data)
    {
        if (root == NULL)
            return;

        greaterTree(root->right, data);
        *data += root->val;
        root->val = *data;
        greaterTree(root->left, data);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        int data = 0;
        greaterTree(root, &data);

        return root;
    }
};