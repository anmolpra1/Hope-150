/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
       map<Node*, Node*> oldToNew;
       return DFS(node, oldToNew);
    }

    Node* DFS(Node* node, map<Node*, Node*> &oldToNew) {
        if (node == nullptr) {
            return nullptr;
        }

        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (auto nei : node->neighbors) {
            copy->neighbors.push_back((DFS(nei, oldToNew)));
        }

        return copy;
    }
};
