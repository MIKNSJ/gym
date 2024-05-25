/**
 * 2024-05-24
 * 
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
        void postOdr(TreeNode* ptrP, TreeNode* ptrQ, unsigned int &pLeft, unsigned int &pRight,unsigned int &qLeft, unsigned int &qRight, bool &same) {
            if (ptrP->left != nullptr && ptrQ->left != nullptr) {
                ++pLeft;
                ++qLeft;
                postOdr(ptrP->left, ptrQ->left, pLeft, pRight, qLeft, qRight, same);
            }

            if (ptrP->left != nullptr && ptrQ->left == nullptr) {
                ++pLeft;
                postOdr(ptrP->left, ptrQ, pLeft, pRight, qLeft, qRight, same);
            }

            if (ptrP->left == nullptr && ptrQ->left != nullptr) {
                ++qLeft;
                postOdr(ptrP, ptrQ->left, pLeft, pRight, qLeft, qRight, same);
            }

            if (ptrP->right != nullptr && ptrQ->right != nullptr) {
                ++pRight;
                ++qRight;
                postOdr(ptrP->right, ptrQ->right, pLeft, pRight, qLeft, qRight, same);
            }

            if (ptrP->right != nullptr && ptrQ->right == nullptr) {
                ++pRight;
                postOdr(ptrP->right, ptrQ, pLeft, pRight, qLeft, qRight, same);
            }

            if (ptrP->right == nullptr && ptrQ->right != nullptr) {
                ++qRight;
                postOdr(ptrP, ptrQ->right, pLeft, pRight, qLeft, qRight, same);
            }

            if (ptrP->val != ptrQ->val || pLeft != qLeft || pRight != qRight) {
                same = false;
                return;
            }
        }

        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p == nullptr && q == nullptr) {
                return true;
            }

            if (p == nullptr && q != nullptr || p != nullptr && q == nullptr) {
                return false;
            }

            bool same = true;
            unsigned int pLeft = 0;
            unsigned int pRight = 0;
            unsigned int qLeft = 0;
            unsigned int qRight = 0;
            postOdr(p, q, pLeft, pRight, qLeft, qRight, same);
            return same;
        }
};