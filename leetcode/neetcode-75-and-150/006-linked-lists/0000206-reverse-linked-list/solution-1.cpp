/**
 * 2024-05-25 
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* curr = head;
            ListNode* prev = head;
            ListNode* tail;
    
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
    
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            tail = curr;
            while (curr != head) {
                if (prev->next == curr) {
                    curr->next = prev;
                    prev->next = nullptr;
                    curr = prev;
                    prev = head;
                } else {
                    prev = prev->next;   
                }
            }
            return tail;
        }
};