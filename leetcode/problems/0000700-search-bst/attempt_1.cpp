// December 22, 2023

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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (val > curr->val) {
                curr = curr->right;
            } else if (val < curr->val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }

        return nullptr;
    }
};
