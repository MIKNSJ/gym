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
        void pathTraversal(TreeNode* curr, int &pathLength, int &maxPathLength) {
            if (curr->left != nullptr) {
                ++pathLength;
                pathTraversal(curr->left, pathLength, maxPathLength);
            }

            if (curr->right != nullptr) {
                ++pathLength;
                pathTraversal(curr->right, pathLength, maxPathLength);
            }

            if (maxPathLength < pathLength) {
                maxPathLength = pathLength;
            }
            
            --pathLength;
        }

        int maxDepth(TreeNode* root) {
            if (root == nullptr) {
                    return 0;
            }

            if (root->left == nullptr && root->right == nullptr) {
                return 1;
            }

            int pathLength = 1;
            int maxPathLength = 1;

            pathTraversal(root, pathLength, maxPathLength);

            return maxPathLength;
        }
};