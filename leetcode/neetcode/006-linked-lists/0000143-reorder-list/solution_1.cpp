/**
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
        void reorderList(ListNode* head) {
            ListNode* slow = head;
            ListNode* slow2 = head;
            ListNode* slow3;
            ListNode* slow4;
            ListNode* fast = head;
    
            while (fast->next != nullptr) {
                if (fast->next != nullptr) {
                    fast = fast->next;
    
                    if (fast->next != nullptr) {
                        fast = fast->next;
                    }
    
                    slow = slow->next;
                }
            }
    
            slow3 = slow;
            slow4 = slow2;
    
            while (slow != fast) {
                while (slow3->next != fast) {
                    slow3 = slow3->next;
                }
    
                slow4 = slow4->next;
                slow2->next = nullptr;
                slow2->next = fast;
                slow2 = slow2->next;
                slow2->next = nullptr;
                slow2->next = slow4;
                slow2 = slow2->next;
                slow3->next = nullptr;
                fast = slow3;
                slow3 = slow;
            }
    
            slow->next = nullptr;
        }
};