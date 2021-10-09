// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> bfs(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> q;

        q.push(root);
        q.push(NULL);
        int val = 0;

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL)
            {
                ans.push_back(val);
                if (q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                val = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }

        return ans;
    }

    vector<int> rightSideView(TreeNode *root)
    {
        if (root)
            return bfs(root);
        return {};
    }
};