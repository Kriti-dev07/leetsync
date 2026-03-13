class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode* dummyNode = new ListNode(0, head);

        ListNode* prevNode = dummyNode;
        ListNode* currNode = head;

        while(currNode && currNode->next){

            prevNode->next = currNode->next;
            currNode->next = currNode->next->next;
            prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }

        return dummyNode->next;
    }
};