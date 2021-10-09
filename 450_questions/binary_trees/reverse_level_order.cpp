// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node *> q; // for bfs

    if (root) // non empty tree
    {
        q.push(root);
        q.push(NULL); // used to divide levels
    }

    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();
        if (x == NULL)
        {
            if (!q.empty())   // if empty => whole tree processed
                q.push(NULL); // end of new level
        }
        else
        {
            // insert front node data in ans
            ans.push_back(x->data);
            // insert left and right childs
            if (x->right)
                q.push(x->right);

            if (x->left)
                q.push(x->left);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}