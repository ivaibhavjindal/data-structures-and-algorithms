// https://leetcode.com/problems/diameter-of-binary-tree/

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
    // O(N)
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    // O(N^2) ([O(N) time at each node due to height and total N nodes])
    int diameter(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        // diameter passes through root
        int d1 = height(root->left) + height(root->right);
        // diameter entirely in left subtree
        int d2 = diameter(root->left);
        // diameter entirely in right subtree
        int d3 = diameter(root->right);

        return max(d1, max(d2, d3));
    }

    // O(N) ([O(1) time at each node due to height and total N nodes])
    pair<int, int> optDiameter(TreeNode *root)
    {
        // height, diameter
        pair<int, int> p;
        if (root == NULL)
        {
            p.first = p.second = 0;
            return p;
        }

        pair<int, int> left = optDiameter(root->left);
        pair<int, int> right = optDiameter(root->right);

        // diameter passes through root (height(left) + height(right))
        int d1 = left.first + right.first;
        // diameter entirely in left subtree (diameter(left))
        int d2 = left.second;
        // diameter entirely in right subtree (diameter(right))
        int d3 = right.second;

        // height(p) = max(height(left), height(right)) + 1
        p.first = max(left.first, right.first) + 1;
        // diamter(p) = max(d1, d2, d3)
        p.second = max(d1, max(d2, d3));

        return p;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        return optDiameter(root).second;
    }
};