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
private:
    int dfs(TreeNode* node, int maxval) {
        if (!node) return 0;

        int res = (node->val >= maxval) ? 1 : 0;
        maxval = max(maxval, node->val);

        res += dfs(node->left, maxval);
        res += dfs(node->right, maxval);  

        return res;
    }    
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        return dfs(root, root->val);
    }
};
