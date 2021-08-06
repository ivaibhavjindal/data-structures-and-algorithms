// https://leetcode.com/problems/symmetric-tree/

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
    bool checkSym(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if ((p != NULL && q == NULL) || (p == NULL && q != NULL))
            return false;

        return ((p->val == q->val) && (checkSym(p->left, q->right)) && (checkSym(p->right, q->left)));
    }
    bool isSymmetric(TreeNode *root)
    {
        return checkSym(root->left, root->right);
    }
};