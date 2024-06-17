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
    // ListNode* reverse(ListNode* head){
    //     ListNode* temp = head;
    //     ListNode* prev= head;
    //     while(temp){
    //         ListNode* front = temp->next;
    //         temp->next= prev;
    //         prev=temp;
    //         temp=front;
    //     }
    //     return prev;

    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1= reverse(l1);
        // l2= reverse(l2);

        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0 ;
        while(l1 != NULL || l2 != NULL){
            int x = (l1 != NULL) ? l1->val : 0 ;
            int y = (l2 != NULL) ? l2->val : 0 ;
            int sum = x+y+carry;

            carry = sum/10;

            curr->next = new ListNode(sum%10);
            curr=curr->next;

            if(l1 != NULL){
                l1=l1->next;
            }
            if(l2!= NULL){
                l2=l2->next;
            }
        }
        if(carry>0){
            curr->next = new ListNode(carry);
            curr=curr->next;
        }
        return dummyNode->next;
    }
};