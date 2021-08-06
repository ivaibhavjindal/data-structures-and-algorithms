// https://www.geeksforgeeks.org/print-nodes-at-k-distance-from-root/

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

void printKLevel(node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
}