// https://leetcode.com/problems/path-sum-ii/

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
    void paths(TreeNode *root, int targetSum, int curSum, vector<int> path, vector<vector<int>> &ans)
    {
        // base case
        if (root == NULL)
            return;

        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            // targeted path
            if (targetSum - curSum == root->val)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }

        // insert node
        path.push_back(root->val);

        // recursive calls
        paths(root->left, targetSum, curSum + root->val, path, ans);
        paths(root->right, targetSum, curSum + root->val, path, ans);

        // remove inserted node
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        paths(root, targetSum, 0, path, ans);
        return ans;
    }
};