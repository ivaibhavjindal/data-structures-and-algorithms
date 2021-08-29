// https://leetcode.com/problems/deepest-leaves-sum/

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
    void levelSum(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        queue<TreeNode *> q; // bfs

        q.push(root);
        q.push(NULL);
        int cur_level_sum = 0;

        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();

            if (t == NULL)
            {
                // store cur level sum
                ans.push_back(cur_level_sum);
                cur_level_sum = 0;

                if (q.empty())
                    return;

                q.push(NULL);
            }
            else
            {

                // update cur sum
                cur_level_sum += t->val;

                // push left and right children
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
    }

    int deepestLeavesSum(TreeNode *root)
    {
        vector<int> ans;
        levelSum(root, ans);

        return ans[ans.size() - 1];
    }
};