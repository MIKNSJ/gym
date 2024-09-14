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
        
        int kthSmallest(TreeNode* root, int k) {
            if (root == nullptr) {
                return -1;
            }
    
            if (root->left == nullptr && root->right == nullptr) {
                return root->val;
            }
    
            vector<int> list;
            inOdrTvl(root, list);
    
            return list[k-1];
        }
};