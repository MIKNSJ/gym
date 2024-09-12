#include "Node.hpp"



// Definition for singly-linked list.
// int val;
// ListNode *next;
ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

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



// Definition for a binary tree node.
// int val;
// TreeNode *left;
// TreeNode *right;
TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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



void printArray(vector<int> &arr) {
    cout << "[";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i + 1 < (int)arr.size()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}



void print2DArray(vector<vector<int>> &arr) {
    cout << "[";
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
