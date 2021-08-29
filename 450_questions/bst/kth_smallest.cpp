// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

class Solution
{
public:
    void inorder(Node *root, int *cur, int *ans, int K)
    {
        if (root != NULL)
        {
            inorder(root->left, cur, ans, K);

            (*cur)++;
            if (K == *cur)
                *ans = root->data;

            inorder(root->right, cur, ans, K);
        }
    }

    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K)
    {
        int ans = -1;
        int cur_smallest = 0;

        inorder(root, &cur_smallest, &ans, K);

        return ans;
    }
};
