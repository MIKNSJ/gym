// Date: YYYY-MM-DD

#include <iostream>      // For standard input/output operations
#include <vector>        // For using vectors
#include <string>        // For using strings
#include <algorithm>     // For algorithms like sort, find, etc.
#include <cmath>         // For mathematical functions like sqrt, pow, etc.
#include <queue>         // For using queues
#include <stack>         // For using stacks
#include <unordered_map> // For using unordered_map (hash map)
#include <unordered_set> // For using unordered_set (hash set)
#include <map>           // For using maps
#include <set>           // For using sets
#include <deque>         // For using double-ended queues
#include <list>          // For using linked lists
#include <utility>       // For using pair and other utilities
#include <tuple>         // For using tuples
#include <variant>       // For working with variant types (C++17 and later)
#include <array>         // For using fixed-size arrays
using namespace std;



// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void addListNodes(ListNode* &head, vector<int> addListNodes) {
        ListNode* curr = head;
    
        for (int i = 0; i < (int)addListNodes.size(); i++) {
            ListNode* newNode = new ListNode(addListNodes[i]);
            curr->next = newNode;
            curr = curr->next;
        }
    
        ListNode* oldHead = head;
        head = head->next;
        delete(oldHead);
    }

    void printList(ListNode* head) {
        ListNode* current = head;
        cout << "[";
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << "]" << endl;
    }
};



// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void printTree(TreeNode* root) {
        if (root == nullptr) {
            cout << "[]" << endl;
            return;
        }
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int nodesAtCurrentLevel = q.size();

            // Print all nodes at current level
            while (nodesAtCurrentLevel > 0) {
                TreeNode* current = q.front();
                q.pop();
                std::cout << current->val << " ";

                // Enqueue left child
                if (current->left != nullptr)
                    q.push(current->left);

                // Enqueue right child
                if (current->right != nullptr)
                    q.push(current->right);

                nodesAtCurrentLevel--;
            }
            cout << endl; // Move to the next level
        }
    }
};



void printArray(vector<int> &arr) {
    cout << "[" << endl;
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i + 1 < (int)arr.size()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}



void print2DArray(vector<vector<int>> &arr) {
    cout << "[" << endl;
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << "[" << endl;
        for (int j = 0; j < (int)arr[i].size(); j++) {
            cout << arr[i][j];
            if (j + 1 < (int)arr[i].size()) {
                cout << ", " << endl;
            }
        }
        cout << "]" << endl;
        if (i + 1 < (int)arr.size()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}



// Definition of Interval:
class Interval {
    public:
        int start, end;
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
};



class Solution {
    public:

};



int main() {
    Solution solution;

    return 0;
}