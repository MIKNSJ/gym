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
        TreeNode* invertTree(TreeNode* root) {
            if (root == nullptr) {
                    return nullptr;
            }

            if (root->left == nullptr && root->right == nullptr) {
                return root;
            }

            queue<TreeNode*> q;
            TreeNode* curr;
            TreeNode* temp;
            q.push(root);

            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                if (curr->right != nullptr) {
                    q.push(curr->right);
                }

                temp = curr->right;
                curr->right = curr->left;
                curr->left = temp;
            }

            return root;
        }
};