class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;

        if (a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(mid));
    }
};
