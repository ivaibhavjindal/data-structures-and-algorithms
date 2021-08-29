// https://practice.geeksforgeeks.org/problems/level-order-traversal/1

/* A binary tree Node

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

class Solution
{
public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *node)
    {
        vector<int> ans;
        queue<Node *> q; // for bfs

        if (node) // non empty tree
        {
            q.push(node);
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
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
        }

        return ans;
    }
};
