// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q; // for bfs

        int cur_level = 0;
        if (root) // non empty tree
        {
            q.push(root);
            q.push(NULL); // used to divide levels
            ans.push_back({});
        }

        while (!q.empty())
        {
            TreeNode *x = q.front();
            q.pop();
            if (x == NULL)
            {
                if (!q.empty()) // if empty => whole tree processed
                {
                    cur_level++; // update cur level
                    ans.push_back({});
                    q.push(NULL); // end of new level
                }
            }
            else
            {
                // insert front node data in ans
                ans[cur_level].push_back(x->val);
                // insert left and right childs
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
        }

        return ans;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans = levelOrder(root);
        int n = ans.size();
        // reverse odd levels
        for (int i = 1; i < n; i += 2)
            reverse(ans[i].begin(), ans[i].end());

        return ans;
    }
};