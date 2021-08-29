// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        return root;
    }

    if (root->data > data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

//Function that constructs BST from its preorder traversal.
Node *constructTree(int pre[], int size)
{
    Node *root = NULL;
    for (int i = 0; i < size; i++)
        root = insert(root, pre[i]);

    return root;
}
