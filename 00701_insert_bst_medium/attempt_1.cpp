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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        if (root == nullptr) {
            TreeNode* newNode = new TreeNode(val);
            root = newNode;
            return root;
        }

        while (curr != nullptr) {
            if (val > curr->val) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    break;
                }
            }

            if (val < curr->val) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    break;
                }
            }
        }

        TreeNode* newNode = new TreeNode(val);

        if (val > curr->val) {
            curr->right = newNode;
        } else  {
            curr->left = newNode;
        }

        return root;
    }
};
