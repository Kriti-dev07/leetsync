class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            prev->next = curr->next;              // step 1
            curr->next = curr->next->next;        // step 2
            prev->next->next = curr;              // step 3

            prev = curr;                          // move prev
            curr = curr->next;                    // move curr
        }

        return dummy->next;
    }
};