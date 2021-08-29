// https://leetcode.com/problems/validate-binary-search-tree/

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
    void inOrder(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            inOrder(root->left, v);
            v.push_back(root->val);
            inOrder(root->right, v);
        }
    }

    bool isInorderSorted(TreeNode *root)
    {
        vector<int> v;
        inOrder(root, v);
        int n = v.size();
        for (int i = 1; i < n; i++)
            if (v[i] <= v[i - 1])
                return false;

        return true;
    }

    bool isValid(TreeNode *root, long mi, long mx)
    {
        if (root == NULL)
            return true;

        if ((root->val > mi) && (root->val < mx))
            return isValid(root->left, mi, root->val) && isValid(root->right, root->val, mx);

        return false;
    }

    bool isValidBST(TreeNode *root)
    {
        // inorder solution
        return isInorderSorted(root);

        // intutive solution
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
