// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    // merge sorted arrays
    vector<int> merge(vector<int> &v1, vector<int> &v2)
    {
        int i = 0, j = 0;
        int n = v1.size();
        int m = v2.size();
        vector<int> ans;

        while (i < n && j < m)
        {
            if (v1[i] < v2[j])
                ans.push_back(v1[i++]);
            else
                ans.push_back(v2[j++]);
        }

        while (i < n)
            ans.push_back(v1[i++]);

        while (j < m)
            ans.push_back(v2[j++]);

        return ans;
    }

    // inorder bst = sorted arr
    void inorderTraversal(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left, v);
            v.push_back(root->val);
            inorderTraversal(root->right, v);
        }
    }

    // find sorted arrays and merge
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        inorderTraversal(root1, v1);
        inorderTraversal(root2, v2);

        return merge(v1, v2);
    }
};