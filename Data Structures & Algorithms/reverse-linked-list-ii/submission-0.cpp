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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy-> next = head;

        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Reverse the given window
        ListNode* curr = prev->next;

        ListNode* revPrev = nullptr;

        for (int i = left; i <= right; i++) {
            ListNode* next = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = next;
        }

        //Reconnect
        ListNode* start = prev->next;

        prev->next = revPrev;
        start->next = curr;

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};