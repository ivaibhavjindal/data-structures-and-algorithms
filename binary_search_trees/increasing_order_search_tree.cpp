// https://leetcode.com/problems/increasing-order-search-tree/

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
    // for flattenToList function
    struct nodepair
    {
        TreeNode *head;
        TreeNode *tail;
    };

    nodepair flattenToList(TreeNode *root)
    {
        nodepair p;

        // base case
        if (root == NULL)
        {
            p.head = p.tail = NULL;
            return p;
        }

        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            p.head = p.tail = root;
            return p;
        }

        // if left and right subtree
        if (root->left && root->right)
        {
            // post order
            nodepair left = flattenToList(root->left);
            nodepair right = flattenToList(root->right);

            // make conncections
            left.tail->right = root;
            root->right = right.head;

            // update head and tail
            p.head = left.head;
            p.tail = right.tail;
        }

        else if (root->left)
        {
            // recursive left subtree call
            nodepair left = flattenToList(root->left);

            // make connections
            left.tail->right = root;

            // update head and tail
            p.head = left.head;
            p.tail = root;
        }

        else if (root->right)
        {
            // recursive right subtree call
            nodepair right = flattenToList(root->right);

            // make connections
            root->right = right.head;

            // update head and tail
            p.head = root;
            p.tail = right.tail;
        }

        return p;
    }

    void nullifyLeft(TreeNode *root)
    {
        TreeNode *temp = root;

        while (temp)
        {
            temp->left = NULL;
            temp = temp->right;
        }
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        root = flattenToList(root).head;
        nullifyLeft(root);

        return root;
    }
};