// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

//Function to find the minimum element in the given BST.
int minValue(Node *root)
{
    int ans = root->data;
    while (root)
    {
        ans = min(ans, root->data);
        root = root->left;
    }

    return ans;
}
