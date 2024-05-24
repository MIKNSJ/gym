// December 25, 2023

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* curr = head;
        set<ListNode*> visited;
        while (curr->next != nullptr) {
            if (visited.find(curr) != visited.end()) {
                return true;
            }

            visited.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};
