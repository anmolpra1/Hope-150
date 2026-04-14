class Solution {
private:
    bool BST(TreeNode* root, long long mini, long long maxi) {
        if (!root) return true;

        if (root->val <= mini || root->val >= maxi) {
            return false;
        }

        return BST(root->left, mini, root->val) &&
               BST(root->right, root->val, maxi);
    }    

public:
    bool isValidBST(TreeNode* root) {
        return BST(root, LLONG_MIN, LLONG_MAX);
    }
};