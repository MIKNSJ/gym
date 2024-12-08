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
        void inOdrTvl(TreeNode* curr, vector<int> &list) {
            if (curr->left != nullptr) {
                inOdrTvl(curr->left, list);
            }
    
            list.push_back(curr->val);
    
            if (curr->right != nullptr) {
                inOdrTvl(curr->right, list);
            }
    
        }
    
        bool isValidBST(TreeNode* root) {
            if (root == nullptr) {
                return true;
            }
    
            if (root->left == nullptr && root->right == nullptr) {
                return true;
            }
    
            vector<int> list;
            inOdrTvl(root, list);
    
            int idxPrevNode = 0;
            for (int i = 1; i < list.size(); i++) {
                if (list[idxPrevNode] >= list[i]) {
                    return false;
                }
    
                idxPrevNode++;
            }
            return true;
        }
};