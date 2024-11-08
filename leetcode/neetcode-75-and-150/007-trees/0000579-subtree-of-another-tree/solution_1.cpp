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
        bool verifyChildren(TreeNode* curr, TreeNode* subCurr) {
            if (curr == nullptr && subCurr == nullptr) {
                return false;
            }
    
            if (curr != nullptr && subCurr == nullptr) {
                return false;
            }
    
            if (curr == nullptr && subCurr != nullptr) {
                return false;
            }
    
            queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            q1.push(curr);
            q2.push(subCurr);
    
            while (true) {
                if (q1.empty() || q2.empty()) {
                    break;
                }
    
                curr = q1.front();
                q1.pop();
    
                subCurr = q2.front();
                q2.pop();
    
                if (curr->left != nullptr) {
                    q1.push(curr->left);
                }
    
                if (subCurr->left != nullptr) {
                    q2.push(subCurr->left);
                }
    
                if (curr->left == nullptr && subCurr->left != nullptr) {
                    return false;
                }
    
                if (curr->right != nullptr) {
                    q1.push(curr->right);
                }
    
                if (subCurr->right != nullptr) {
                    q2.push(subCurr->right);
                }
    
                if (curr->right == nullptr && subCurr->right != nullptr) {
                    return false;
                }
    
                if (curr->val != subCurr->val) {
                    return false;
                }
    
                if (q1.size() != q2.size()) {
                    return false;
                }
            }
            
            return true;
        }
    
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if (root == nullptr && subRoot == nullptr) {
                return false;
            }
    
            if (root != nullptr && subRoot == nullptr) {
                return false;
            }
    
            if (root == nullptr && subRoot != nullptr) {
                return false;
            }
    
            queue<TreeNode*> q3;
            q3.push(root);
    
            while(!q3.empty()) {
                TreeNode* curr = q3.front();
                q3.pop();
                cout << curr->val << endl;
    
                if (verifyChildren(curr, subRoot)) {
                    return true;
                }
    
                if (curr->left != nullptr) {
                    q3.push(curr->left);
                }
    
                if (curr->right != nullptr) {
                    q3.push(curr->right);
                }
            }
    
            return false;
        }
};