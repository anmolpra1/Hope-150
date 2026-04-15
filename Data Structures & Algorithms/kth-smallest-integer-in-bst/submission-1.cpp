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
    int kthSmallest(TreeNode* root, int k) {
        // using Morris Order Traversal to avoid the stack space
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == NULL) {
                k--;
                if (k == 0) return curr->val;
                curr = curr->right;
            }               

            else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else{ // if the thread already exist
                    prev->right = NULL;
                    k--;
                    if (k == 0) return curr->val;
                    curr= curr->right;
                }
            }
        }
        return -1;
    }
};
