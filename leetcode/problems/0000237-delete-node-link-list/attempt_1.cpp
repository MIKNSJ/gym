// December 23, 2023

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = curr;

        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
            prev->val = curr->val;
        }

        prev->next = nullptr;
    }
};
