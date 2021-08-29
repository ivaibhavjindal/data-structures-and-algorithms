// https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

class Solution
{
public:
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        int min_diff = INT_MAX;
        Node *temp = root;

        while (temp != NULL)
        {
            int cur_diff = abs(temp->data - K);
            min_diff = min(cur_diff, min_diff);

            if (K < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        return min_diff;
    }
};