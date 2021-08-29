// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    void sumPath(TreeNode *root, int *ans, string path)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            *ans += stoi(path + to_string(root->val), 0, 2);
        }

        sumPath(root->left, ans, path + to_string(root->val));
        sumPath(root->right, ans, path + to_string(root->val));
    }

    int sumRootToLeaf(TreeNode *root)
    {
        int ans = 0;
        sumPath(root, &ans, "");
        return ans;
    }
};