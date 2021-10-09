// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> bfs(Node *root)
{
    vector<int> ans;
    queue<Node *> q;

    q.push(root);
    q.push(NULL);
    int val = 0;

    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if (cur == NULL)
        {
            ans.push_back(val);
            if (q.empty())
                break;
            q.push(NULL);
        }
        else
        {
            val = cur->data;
            if (cur->right)
                q.push(cur->right);
            if (cur->left)
                q.push(cur->left);
        }
    }

    return ans;
}

vector<int> leftView(Node *root)
{
    if (root)
        return bfs(root);
    return {};
}