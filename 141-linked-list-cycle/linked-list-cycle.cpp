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
   ListNode* slow = head;
   ListNode* fast=  head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;    // if the loop is not there move the slow pointer by one and fast pointer by two
    
        if(slow==fast){
            return true;     //loop is detected;
        }
   }
   return false;
    }
};