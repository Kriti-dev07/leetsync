class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode* dummyNode = new ListNode(0, head); //creates a node named dummy and its value is 0 while its next is head 

        ListNode* prevNode = dummyNode;        
        ListNode* currNode = head;

        while(currNode && currNode->next){  //currNode and currNode->next node exists 

            prevNode->next = currNode->next;
          
            currNode->next = currNode->next->next;
              prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }

        return dummyNode->next;
    }
};