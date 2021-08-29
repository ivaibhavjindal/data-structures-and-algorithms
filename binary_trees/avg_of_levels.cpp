// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
class Solution {
public:
    void avgLevel(TreeNode *root, vector<double> &ans) {
        if(root == NULL)
            return;
        
        queue<TreeNode *> q; // bfs
        
        q.push(root);
        q.push(NULL);
        double cur_level_sum = 0;
        double cur_level_nodes = 0;
        
        while(!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            
            if(t == NULL) {
                // store avg val at each level
                ans.push_back(cur_level_sum/cur_level_nodes);
                cur_level_sum = 0;
                cur_level_nodes = 0;

                if(q.empty())
                    return;
                
                q.push(NULL);
                
            } else {
                
                // update cur sum and num nodes
                cur_level_sum += t->val;   
                cur_level_nodes++;
                
                // push left and right children
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);                    
            }
        }   
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        avgLevel(root, ans);
        return ans;
    }
};