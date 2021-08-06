// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int levelOrder(TreeNode *root)
    {
        int ans = 0, curlevelsum = 0, maxsum = INT_MIN;

        queue<TreeNode *> q; // for bfs

        int cur_level = 0;
        if (root) // non empty tree
        {
            q.push(root);
            q.push(NULL); // used to divide levels
        }

        while (!q.empty())
        {
            // get front node and pop it
            TreeNode *x = q.front();
            q.pop();

            if (x == NULL) // end of level
            {
                // update sum if max
                if (curlevelsum > maxsum)
                {
                    ans = cur_level;
                    maxsum = curlevelsum;
                }
                if (!q.empty())
                {
                    cur_level++;  // update cur level
                    q.push(NULL); // end of new level
                }
                curlevelsum = 0; // reset curlevelsum
            }
            else
            {
                // add front node data in curlevelsum
                curlevelsum += (x->val);
                // insert left and right childs
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
        }

        return ans;
    }

    int maxLevelSum(TreeNode *root)
    {
        // levels start from 1
        return levelOrder(root) + 1;
    }
};
