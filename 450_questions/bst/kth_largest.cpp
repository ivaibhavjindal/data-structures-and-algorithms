// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void reverseInorder(Node *root, int *cur, int *ans, int K)
    {
        if (root != NULL)
        {
            reverseInorder(root->right, cur, ans, K);

            (*cur)++;
            if (K == *cur)
                *ans = root->data;

            reverseInorder(root->left, cur, ans, K);
        }
    }

    int kthLargest(Node *root, int K)
    {
        int ans = -1;
        int cur_largest = 0;

        reverseInorder(root, &cur_largest, &ans, K);

        return ans;
    }
};
