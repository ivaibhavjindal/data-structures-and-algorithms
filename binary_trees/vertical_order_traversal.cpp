// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    // tree traversal helper
    void treeTraversal(TreeNode *root, int d, int h, map<int, vector<pair<int, int>>> &mp)
    {
        if (root == NULL)
            return;

        mp[d].push_back({h, root->val});
        treeTraversal(root->left, d - 1, h + 1, mp);
        treeTraversal(root->right, d + 1, h + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> mp;
        treeTraversal(root, 0, 0, mp);

        // keys are sorted
        vector<vector<int>> ans;
        for (auto p : mp)
        {
            // sort by height
            sort(p.second.begin(), p.second.end());
            vector<int> temp;
            for (auto v : p.second)
                temp.push_back(v.second);
            ans.push_back(temp);
        }
        return ans;
    }
};