/**
 * 2024-05-26
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
           ListNode* curr2 = list2;
           ListNode* merged = new ListNode(-1);
           ListNode* curr3 = merged;

           while (true) {
               if (curr1 == nullptr && curr2 != nullptr) {
                   curr3->next = curr2;
                   break;
               } else if (curr1 != nullptr && curr2 == nullptr) {
                   curr3->next = curr1;
                   break;
               } else if (curr1 == nullptr && curr2 == nullptr) {
                   return list1;
               } else if (curr1->val <= curr2->val) {
                   curr3->next = curr1;
                   curr1 = curr1->next;
               } else {
                   curr3->next = curr2;
                   curr2 = curr2->next;
               }
               curr3 = curr3->next;
           }
           return merged->next;
    }
};