#include <iostream>
#include <queue>
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

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
/* Tree
            1
        2      3
     4    5      6
         7
*/
node *preOrderBuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;

    node *n = new node(d);
    n->left = preOrderBuildTree();
    n->right = preOrderBuildTree();

    return n;
}

// Input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
/* Tree
            1
        2      3
     4    5      6
         7
*/
node *levelOrderBuildTree()
{
    vector<int> v = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
    node *root = new node(1);

    queue<node *> q;
    q.push(root);

    for (int i = 1; i < v.size() - 1; i += 2)
    {
        node *x = q.front();
        q.pop();

        // left child of cur node
        if (v[i] == -1)
            x->left = NULL;
        else
        {
            x->left = new node(v[i]);
            q.push(x->left);
        }

        // right child of cur node
        if (v[i + 1] == -1)
            x->right = NULL;
        else
        {
            x->right = new node(v[i + 1]);
            q.push(x->right);
        }
    }

    return root;
}