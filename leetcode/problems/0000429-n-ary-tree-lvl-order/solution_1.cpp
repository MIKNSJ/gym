/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> order;
            vector<int> level;

            if (root == nullptr) {
                return order;
            }

            if (root->children.size() == 0) {
                level.push_back(root->val);
                order.push_back(level);
                return order;
            }

            queue<Node*> q;
            Node* temp;
            int countChildren = 0;
            int countThreshold = 0;
            int count = 0;
            q.push(root);

            level.push_back(root->val);
            order.push_back(level);
            countChildren++;
            countThreshold = countChildren;
            countChildren = 0;
            level.clear();

            while (!q.empty()) {
                Node* curr = q.front();
                q.pop();

                for (int i = 0; i < curr->children.size(); i++) {
                    if (curr->children[i] != nullptr) {
                        q.push(curr->children[i]);
                        level.push_back(curr->children[i]->val);
                        countChildren++;
                    }
                }

                count++;

                if (level.size() > 0 && count == countThreshold) {
                    order.push_back(level);
                    level.clear();
                    countThreshold = countChildren;
                    countChildren = 0;
                    count = 0;
                }
            }

            return order;
        }
};