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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        if(head==NULL){
            return NULL;
        }
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count == n){
            ListNode* newHead = head->next;
            delete (head);
            return newHead;
        }
        temp=head;
        int deleteCount = count-n ;
        
       while(temp!=NULL){
        deleteCount--;
        if(deleteCount==0){
            break;
        }
            temp=temp->next;
            
        
       }
       ListNode* freeNode= temp->next;
       temp->next=temp->next->next;
       delete(freeNode);
       return head;

       
    }
};