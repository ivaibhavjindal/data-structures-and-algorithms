// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    struct llpair
    {
        TreeNode *head;
        TreeNode *tail;
    };

    llpair tree2ll(TreeNode *root)
    {
        llpair p;

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

        // left and right subtree
        if (root->left && root->right)
        {
            llpair left = tree2ll(root->left);
            llpair right = tree2ll(root->right);

            left.tail->right = right.head;
            root->right = left.head;

            p.head = root;
            p.tail = right.tail;
        }

        // if only left subtree
        else if (root->left)
        {
            llpair left = tree2ll(root->left);

            root->right = left.head;

            p.head = root;
            p.tail = left.tail;
        }

        // if only right subtree
        else if (root->right)
        {
            llpair right = tree2ll(root->right);

            root->right = right.head;

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

    void flatten(TreeNode *root)
    {
        root = tree2ll(root).head;
        nullifyLeft(root);
    }
};
