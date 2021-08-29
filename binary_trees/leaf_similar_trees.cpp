// https://leetcode.com/problems/leaf-similar-trees/

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
    void leaveSeq(TreeNode *root, vector<int> &seq)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            seq.push_back(root->val);

        leaveSeq(root->left, seq);
        leaveSeq(root->right, seq);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> seq1, seq2;
        leaveSeq(root1, seq1);
        leaveSeq(root2, seq2);

        int n = seq1.size();
        int m = seq2.size();

        if (n == m)
        {
            for (int i = 0; i < n; i++)
            {
                if (seq1[i] != seq2[i])
                    return false;
            }
            return true;
        }

        return false;
    }
};