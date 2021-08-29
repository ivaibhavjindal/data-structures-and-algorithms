// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to return level order traversal
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        queue<Node *> q; // for bfs

        int cur_level = 0;
        if (root) // non empty tree
        {
            q.push(root);
            q.push(NULL); // used to divide levels
            ans.push_back({});
        }

        while (!q.empty())
        {
            Node *x = q.front();
            q.pop();
            if (x == NULL)
            {
                if (!q.empty()) // if empty => whole tree processed
                {
                    cur_level++; // update cur level
                    ans.push_back({});
                    q.push(NULL); // end of new level
                }
            }
            else
            {
                // insert front node data in ans
                ans[cur_level].push_back(x->data);
                // insert left and right childs
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
        }

        return ans;
    }

    //Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> ans;
        vector<vector<int>> level = levelOrder(root);
        int n = level.size();

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                reverse(level[i].begin(), level[i].end());
            for (auto x : level[i])
                ans.push_back(x);
        }

        return ans;
    }
};
