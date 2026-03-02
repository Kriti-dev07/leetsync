/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool found= false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!= NULL){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast){
                found=true;
                break;

            }
           
        }
         return found ;
    }
};