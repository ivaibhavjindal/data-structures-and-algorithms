// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
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
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }

        return ans;
    }

    vector<int> rightView(Node *root)
    {
        if (root)
            return bfs(root);
        return {};
    }
};