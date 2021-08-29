// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    void levelLargest(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        queue<TreeNode *> q; // bfs

        q.push(root);
        q.push(NULL);
        int cur_max = INT_MIN;

        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();

            if (t == NULL)
            {
                // store max val at each level
                ans.push_back(cur_max);
                cur_max = INT_MIN;

                if (q.empty())
                    return;

                q.push(NULL);
            }
            else
            {
                // update cur max
                cur_max = max(cur_max, t->val);

                // push left and right children
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
    }

    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        levelLargest(root, ans);
        return ans;
    }
};