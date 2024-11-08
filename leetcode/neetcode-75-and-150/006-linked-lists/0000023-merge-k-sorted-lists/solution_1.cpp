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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            vector<ListNode*> curr;
            int end = 0;
            int min_idx;
            ListNode* minimum;
    
            if ((int)lists.size() == 0) {
                return nullptr;
            }
    
            if ((int)lists.size() == 1) {
                return lists[0];
            }
    
            for (int i = 0; i < (int)lists.size(); i++) {
                if (lists[i] == nullptr) {
                    lists.erase(lists.begin() + i);
                }
            }
    
            if (end == (int)lists.size()) {
                return nullptr;
            }
    
            ListNode* dummy = new ListNode();
            ListNode* dummy_curr = dummy;
    
            for (int i = 0; i < (int)lists.size(); i++) {
                ListNode* ptr = lists[i];
                curr.push_back(ptr);
            }
    
            minimum = lists[0];
            while (true) {
                for (int i = 0; i < (int)curr.size(); i++) {
                    if (curr[i] == nullptr) {
                        end++;
                    } else {
                        minimum = curr[i];
                    }
                }
    
                if (end == (int)lists.size()) {
                    return dummy->next;
                }
                end = 0;
    
                for (int i = 0; i < (int)lists.size(); i++) {
                    if (curr[i] != nullptr) {
                        //if (dummy_curr->val <= curr[i]->val) {
                            if (minimum->val >= curr[i]->val) {
                                minimum = curr[i];
                                min_idx = i;
                            }
                        //}
                    }
                }
    
                if (curr[min_idx] != nullptr) {
                    curr[min_idx] = curr[min_idx]->next;
                }
    
                dummy_curr->next = minimum;
                dummy_curr = dummy_curr->next;
            }
        }
};