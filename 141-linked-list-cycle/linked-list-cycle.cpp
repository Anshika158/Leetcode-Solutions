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
    
    // HASHING APPROACH
        // unordered_map<ListNode* , int> mpp;
        // ListNode* curr = head;
        // while(curr!=NULL){
        //     if(mpp.find(curr)!=mpp.end()){
        //         return true;
        //     }
        //     mpp[curr]=1;
        //     curr=curr->next;
        // }
        // return false;

    //SLOW AND FAST POINTER APPROACH
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};