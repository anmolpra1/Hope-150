/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* next;
     Node* random;
     
     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Edge case: empty list
        if (head == NULL) return NULL;

        // Map: original node -> copied node
        unordered_map<Node*, Node*> mp;

        // Create head of copied list
        Node* newHead = new Node(head->val);

        Node* oldTemp = head->next;   // traverse original list
        Node* newTemp = newHead;      // build copied list

        // Store mapping for head
        mp[head] = newHead;

        // Step 1: Copy all nodes (only next pointers)
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);

            mp[oldTemp] = copyNode;        // map original → copy
            newTemp->next = copyNode;      // link copied list

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 2: Assign random pointers using map
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) {
            // Map original random to copied random
            newTemp->random = mp[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Return head of deep copied list
        return newHead;
    }
};