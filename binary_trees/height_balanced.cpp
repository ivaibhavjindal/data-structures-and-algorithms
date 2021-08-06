// https://leetcode.com/problems/balanced-binary-tree/

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
    // O(N) [(O(1)) work for each node and total N nodes]
    // if we use separate height function then it will become O(N^2)
    pair<bool, int> checkBalance(TreeNode *root)
    {
        // isbalanced, height
        pair<bool, int> p;

        // base case (single node = balanced)
        if (root == NULL)
        {
            p.first = true;
            p.second = 0;

            return p;
        }

        pair<bool, int> left = checkBalance(root->left);
        pair<bool, int> right = checkBalance(root->right);

        // left and right are height balanced, and abs(difference in heights) < 2
        if (left.first && right.first && abs(left.second - right.second) <= 1)
            p.first = true;
        else
            p.first = false;

        // height(p) = max(height(left), height(right))+1
        p.second = max(left.second, right.second) + 1;

        return p;
    }

    bool isBalanced(TreeNode *root)
    {
        return checkBalance(root).first;
    }
};