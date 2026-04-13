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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& maxDiameter) {
        if (!root) return 0;

        int lh = dfs(root->left, maxDiameter);
        int rh = dfs(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, lh + rh);

        return 1 + max(lh, rh);
    }
};