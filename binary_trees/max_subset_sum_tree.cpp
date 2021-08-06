// https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

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

// O(N)
pair<int, int> maxSubsetSum(node *root)
{
    // inc, exc
    pair<int, int> p;
    // base case
    if (root == NULL)
    {
        p.first = p.second = 0;
        return p;
    }

    // recursive case
    pair<int, int> left = maxSubsetSum(root->left);
    pair<int, int> right = maxSubsetSum(root->right);

    // include root => exclude left and right child
    p.first = root->data + left.second + right.second;
    // exclude root => max of left and right child
    p.second = max(max(left.first, left.second), max(right.first, right.second));

    return p;
}

int maxSubSum(node *root)
{
    pair<int, int> ans = maxSubsetSum(root);

    return max(ans.first, ans.second);
}