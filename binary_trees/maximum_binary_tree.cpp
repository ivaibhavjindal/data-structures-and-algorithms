// https://leetcode.com/problems/maximum-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // helper function to find index of max element in [start,end]
    int findMax(vector<int> &nums, int start, int end)
    {
        int idx = start, max_elem = INT_MIN;
        for (int i = start; i <= end; i++)
        {
            if (nums[i] > max_elem)
            {
                max_elem = nums[i];
                idx = i;
            }
        }

        return idx;
    }

    TreeNode *maxBinaryTree(vector<int> &nums, int start, int end)
    {
        // base case
        if (start > end)
            return NULL;

        // parition node
        int idx = findMax(nums, start, end);
        TreeNode *root = new TreeNode(nums[idx]);

        // recursive fill left and right subtree
        root->left = maxBinaryTree(nums, start, idx - 1);
        root->right = maxBinaryTree(nums, idx + 1, end);

        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return maxBinaryTree(nums, 0, nums.size() - 1);
    }
};