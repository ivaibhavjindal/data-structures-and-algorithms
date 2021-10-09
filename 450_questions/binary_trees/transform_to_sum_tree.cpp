// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    struct tree
    {
        int sum;
    };

    tree *sumTree(Node *node)
    {
        tree *cur = new tree();
        cur->sum = 0;

        if (node == NULL)
            return cur;

        int nodeval = node->data;
        node->data = sumTree(node->left)->sum + sumTree(node->right)->sum;
        cur->sum = node->data + nodeval;

        return cur;
    }

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        sumTree(node);
    }
};