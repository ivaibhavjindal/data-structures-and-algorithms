// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    // search if node with given key present in bst => O(H)
    bool search(TreeNode *root, int key)
    {
        if (root == NULL)
            return false;

        if (root->val == key)
            return true;

        if (key < root->val)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // visit each node and perform search => O(N * H)
    bool find(TreeNode *root, TreeNode *head, int k)
    {
        // base case
        if (root == NULL)
            return false;

        // given unique values in bst, search if remaining sum can be found
        if ((k != 2 * root->val) && (search(head, (k - root->val)) || (search(head, (k - root->val)))))
            return true;

        // recursively check for each node in left and right subtree
        return (find(root->left, head, k)) || (find(root->right, head, k));
    }

    bool findTarget(TreeNode *root, int k)
    {
        return find(root, root, k);
    }
};