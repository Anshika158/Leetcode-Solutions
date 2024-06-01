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
    struct ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(temp!=NULL){
            ListNode* front = NULL;
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        head=prev;
        return head;
    }


    bool isPalindrome(ListNode* head) {
       //find the middle
        ListNode* slow = head;
        ListNode* fast  = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       //reverse the linked list
        ListNode* newHead = reverse(slow->next);

       //comparision
       ListNode* first = head;
       ListNode* second = newHead;
       while(second!=NULL){
        if(first->val != second->val ){
            reverse(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
       }
       return true;


           
        
    }
};