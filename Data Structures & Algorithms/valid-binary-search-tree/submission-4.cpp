class Solution {
private:
    bool BST(TreeNode* root, long long mini, long long maxi) {
        if (!root) return true;

        if (root->val <= mini || root->val >= maxi) {
            return false;
        }

        bool left = BST(root->left, mini, root->val);
        bool right = BST(root->right, root->val, maxi);

        return left && right;
               
    }    

public:
    bool isValidBST(TreeNode* root) {
        return BST(root, LLONG_MIN, LLONG_MAX);
    }
};