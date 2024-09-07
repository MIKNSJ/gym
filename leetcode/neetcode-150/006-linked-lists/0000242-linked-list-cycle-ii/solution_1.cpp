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
        ListNode* detectCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* slow_two = head;
            ListNode* fast = head;
        
            if (head == nullptr) {
                return nullptr;
            }
        
            while (true) {
                if (fast->next != nullptr) {
                    fast = fast->next;
        
                    if (fast->next != nullptr) {
                        fast = fast->next;
                    } else {
                        return nullptr;
                    }
                } else {
                    return nullptr;
                }
        
                slow = slow->next;
        
                if (slow == fast) {
                    break;
                }
            }
        
            while (true) {
                if (slow == slow_two) {
                    break;
                }
        
                slow = slow->next;
                slow_two = slow_two->next;
            }
        
            return slow;
        }
};
