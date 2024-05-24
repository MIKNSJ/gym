// December 23, 2023

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = curr;
        int idx = 0;
        int size = 1;

        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        while (curr->next != nullptr) {
            curr = curr->next;
            size++;
        }

        if (size - n == 0) {
            head = head->next;
            return head;
        }

        curr = head;
        while (curr != nullptr) {
            if (idx == size - n) {
                prev->next = curr->next;
                break;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        return head;
    }
};
