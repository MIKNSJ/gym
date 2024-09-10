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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> order;
            vector<int> level;
    
            if (root == nullptr) {
                return order;
            }
    
            if (root->left == nullptr && root->right == nullptr) {
                level.push_back(root->val);
                order.push_back(level);
                return order;
            }
    
            queue<TreeNode*> q;
            TreeNode* curr;
            TreeNode* temp;
            int countChildren = 0;
            int countThreshold = 2;
            q.push(root);
    
            level.push_back(root->val);
            order.push_back(level);
            level.clear();
    
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
    
                if (curr->left != nullptr) {
                    level.push_back(curr->left->val);
                    countChildren++;
                    q.push(curr->left);
                } else {
                    countThreshold--;
                }
    
                if (curr->right != nullptr) {
                    level.push_back(curr->right->val);
                    countChildren++;
                    q.push(curr->right);
                } else {
                    countThreshold--;
                }
    
                if (level.size() > 0 && countChildren == countThreshold) {
                    order.push_back(level);
                    level.clear();
                    countChildren = 0;
                    countThreshold*=2;
                }
            }
    
            return order;
        }
};