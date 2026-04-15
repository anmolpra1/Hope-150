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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                         int &preIdx, int left, int right) {

        if (left > right) return nullptr;                    

        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;

        int inIdx = search(root->val, inorder, left, right);

        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right); 

        return root;                   
     }

     int search(int root, vector<int>& inorder, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == root) {
                return i;
            }
        }
        return -1;
     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0;
        int right = inorder.size()-1;
        int preIdx = 0;

        return helper(preorder, inorder, preIdx, left, right);  // 0->preorder index
    }
};
