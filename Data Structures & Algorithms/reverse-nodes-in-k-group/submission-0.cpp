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
    // Reverses a standard linked list and returns the new head
    ListNode* reverseLL(ListNode* temp) {
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            ListNode* curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }

    // Finds the k-th node from the current position
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    // Reverses nodes in k-group chunks
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getKthNode(temp, k);

            // If less than k nodes are left, keep them as-is and stop
            if (kthNode == nullptr) {
                if (prevLast != nullptr) {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr; // Isolate the current k-group

            ListNode* newHead = reverseLL(temp); // Reverse the k-group

            // Update the head of the whole list on the first reversal
            if (temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead; // Link previous group to current
            }

            prevLast = temp; // 'temp' is now the tail of the reversed group
            temp = nextNode; // Move to the next group
        }

        return head;
    }
};