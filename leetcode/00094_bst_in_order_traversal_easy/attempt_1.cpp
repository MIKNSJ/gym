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
    void inOdrTravHelper(TreeNode* curr, vector<int> & nodes) {
                if (curr->left != nullptr) {
                    inOdrTravHelper(curr->left, nodes);
                }

                nodes.push_back(curr->val);

                if (curr->right != nullptr) {
                    inOdrTravHelper(curr->right, nodes);
                }
    }


    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> val_nodes;

        if (root == nullptr) {
            return val_nodes;
        }

        inOdrTravHelper(curr, val_nodes);

        return val_nodes;
    }
};
