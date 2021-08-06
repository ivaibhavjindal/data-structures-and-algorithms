// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void printAtLevelK(TreeNode *root, int k, vector<int> &ans)
    {
        if (root == NULL || k < 0)
            return;

        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }

        printAtLevelK(root->left, k - 1, ans);
        printAtLevelK(root->right, k - 1, ans);
    }

    int nodesAtDistanceK(TreeNode *root, TreeNode *target, int k, vector<int> &ans)
    {
        // base case
        if (root == NULL)
            return -1;

        // print descendant of target at distance k
        if (target == root)
        {
            printAtLevelK(root, k, ans);
            // return distance to target from current node
            return 0;
        }

        // recursive left subtree
        int dl = nodesAtDistanceK(root->left, target, k, ans);
        // if target node in left subtree
        if (dl != -1)
        {
            // if root is at given distance
            if (dl + 1 == k)
                ans.push_back(root->val);
            // nodes in right subtree
            else
                printAtLevelK(root->right, k - 2 - dl, ans);

            // return distance to target from current node
            return 1 + dl;
        }

        // recursive right subtree
        int dr = nodesAtDistanceK(root->right, target, k, ans);
        if (dr != -1)
        {
            // if root is at given distance
            if (dr + 1 == k)
                ans.push_back(root->val);
            // nodes in left subtree
            else
                printAtLevelK(root->left, k - 2 - dr, ans);

            // return distance to target from current node
            return 1 + dr;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        nodesAtDistanceK(root, target, k, ans);
        return ans;
    }
};