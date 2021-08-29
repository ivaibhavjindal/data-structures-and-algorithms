// https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/

#include <bits/stdc++.h>
using namespace std;

// node of bst
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// for flattenToList function
struct nodepair
{
    node *head;
    node *tail;
};

nodepair flattenToList(node *root)
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

// helper print list
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
}

// helper insert bst nodes
node *insertIntoBST(node *root, int val)
{
    if (root == NULL)
        return new node(val);

    if (val < root->data)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

int main()
{
    node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int x : arr)
        root = insertIntoBST(root, x);

    root = flattenToList(root).head;

    printList(root);
}