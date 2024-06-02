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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        int count=1;
        ListNode* temp = head;
        while(temp->next!=NULL){
        count++;
        temp=temp->next;
        }
        // if(count==k || k%count==0){
        //     return head;
        // }
        // // we have to rotate till k will not become zero;
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        // while(k!=0){
        // while(fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next;
        // }
        // ListNode* storeHead = head;
        // fast->next=head;
        // head->next=storeHead;
        // slow->next=NULL;
        // }

        // return head;

         temp->next=head;

         k=k%count;
         int newK = count - k ;

          ListNode* newTail = head;
        for (int i = 1; i < newK; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break the circular list to get the new head
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};