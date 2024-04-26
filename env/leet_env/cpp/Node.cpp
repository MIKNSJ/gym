#include "Node.hpp"



// Definition for singly-linked list.
// int val;
// ListNode *next;
ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}



// Definition for a binary tree node.
// int val;
// TreeNode *left;
// TreeNode *right;
TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}