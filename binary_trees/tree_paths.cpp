// https://leetcode.com/problems/binary-tree-paths/

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
    void paths(TreeNode *root, string path, vector<string> &ans)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            ans.push_back(path + to_string(root->val));

        paths(root->left, path + to_string(root->val) + "->", ans);
        paths(root->right, path + to_string(root->val) + "->", ans);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        paths(root, "", ans);
        return ans;
    }
};