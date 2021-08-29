// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

//Function to insert a node in a BST.
Node *insert(Node *root, int Key)
{
    if (root == NULL)
        return new Node(Key);

    if (Key == root->data)
        return root;
    else if (Key < root->data)
        root->left = insert(root->left, Key);
    else
        root->right = insert(root->right, Key);

    return root;
}
