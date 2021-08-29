// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements
{
public:
    // maintain node list
    unordered_set<int> st;

    FindElements(TreeNode *root)
    {
        recoverElements(root, 0);
    }

    void recoverElements(TreeNode *root, int val)
    {
        if (root == NULL)
            return;

        // recover current node
        root->val = val;
        st.insert(val);

        // recursively recover left and right subtree
        recoverElements(root->left, 2 * val + 1);
        recoverElements(root->right, 2 * val + 2);
    }

    bool find(int target)
    {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */