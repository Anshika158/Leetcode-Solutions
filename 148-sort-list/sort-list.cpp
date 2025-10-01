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
   
    ListNode* sortList(ListNode* head) {

//INTUTION MERGE SORT APPROACH
        // Step-1 Split the middle into two halves
        if (!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next=nullptr;

        // Step-2 Sort each part
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        //Step-3 Merge two sorted halves
        return merge(left , right);
    }
     ListNode* merge(ListNode* l1 , ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }tail=tail->next;
        }
        if(l1!=nullptr){
            tail->next=l1;
        }else{
            tail->next=l2;
        }
        return dummy->next;
    }
};