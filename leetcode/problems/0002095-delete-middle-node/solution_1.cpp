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
        ListNode* deleteMiddle(ListNode* head) {
            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* slow2 = head;

            if (head == nullptr) {
                return nullptr;
            }

            if (head->next == nullptr) {
                delete(head);
                return nullptr;
            }

            while (fast->next != nullptr) {
                if (fast->next != nullptr) {
                    fast = fast->next;

                    if (fast->next != nullptr) {
                        fast = fast->next;
                    }

                    slow = slow->next;
                }
            }

            while (slow2->next != slow) {
                slow2 = slow2 -> next;
            }
            
            slow2->next = slow->next;
            delete(slow);

            return head;
        }
};