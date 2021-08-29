// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

/* Tree node structure  used in the program
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

class Solution
{
public:
    int height(Node *root, map<int, int> *mp)
    {
        if (root == NULL)
            return 0;

        int h = 1 + max(height(root->left, mp), height(root->right, mp));
        (*mp)[h]++;

        return h;
    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        map<int, int> mp;
        height(root, &mp);

        int diameter = 1;
        for (auto p : mp)
            diameter = max(diameter, p.second);

        return diameter;
    }
};
