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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* curr_l1 = l1;
            ListNode* curr_l2 = l2;
            ListNode* l3 = new ListNode(0);
            ListNode* curr_l3 = l3;
            int l1_val, l2_val, newVal;
            int carry = 0;
            bool l1_end = false;
            bool l2_end = false;
    
            while (true) {
                if (l1_end && l2_end) {
                    break;
                }
                
                if (l1_end) {
                    l1_val = 0;
                } else {
                    l1_val = curr_l1->val;
                }
    
                if (l2_end) {
                    l2_val = 0;
                } else {
                    l2_val = curr_l2->val;
                }
    
                newVal = l1_val + l2_val + carry;
    
                if (newVal >= 10) {
                    carry = 1;
                    newVal-=10;
                } else {
                    carry = 0;
                }
    
                ListNode* newNode = new ListNode(newVal);
                curr_l3->next = newNode;
                curr_l3 = curr_l3->next;
    
                if (curr_l1->next == nullptr) {
                    l1_end = true;
                } else {
                    curr_l1 = curr_l1->next;
                }
    
                if (curr_l2->next == nullptr) {
                    l2_end = true;
                } else {
                    curr_l2 = curr_l2->next;
                }
            }
    
            if (carry == 1) {
                ListNode* newNode = new ListNode(carry);
                curr_l3->next = newNode;
                curr_l3 = curr_l3->next;
            }
    
            return l3->next;
        }
};