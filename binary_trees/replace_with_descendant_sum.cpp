// https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

int replaceWithDescSum(node *root)
{
    // base case
    if (root == NULL)
        return 0;

    // leaf node
    if (root->right == NULL && root->left == NULL)
        return root->data;

    // recursive for left and right subtree
    int left = replaceWithDescSum(root->left);
    int right = replaceWithDescSum(root->right);

    // update cur node data with descendant sum
    int temp = root->data;
    root->data = left + right;

    // data for parent
    return root->data + temp;
}