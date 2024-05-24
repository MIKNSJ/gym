// January 3, 2024

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
        void postOdrTravHelper(TreeNode* curr, vector<int> & nodes) {
            if (curr->left != nullptr) {
                postOdrTravHelper(curr->left, nodes);
            }

            if (curr->right != nullptr) {
                postOdrTravHelper(curr->right, nodes);
            }

            nodes.push_back(curr->val);
        }


        vector<int> postorderTraversal(TreeNode* root) {
            TreeNode* curr = root;
            vector<int> val_nodes;

            if (root == nullptr) {
                return val_nodes;
            }

            postOdrTravHelper(curr, val_nodes);

            return val_nodes;
        }
};
