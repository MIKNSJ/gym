// ===== Established 2024 ========================
//
//  Functionality: Sets up Leetcode DS env.
//
// ===============================================



#ifndef Node_hpp
#define Node_hpp

using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
 };



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};



#endif