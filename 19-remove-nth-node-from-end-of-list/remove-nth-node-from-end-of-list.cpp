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
        ListNode* fast = head ;
        for(int i=0 ; i<n ; i++ ){
            fast=fast->next;
        }
         if (fast == nullptr) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        ListNode* slow = head;
        while(fast->next != nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* del = slow->next;
        slow->next=slow->next->next;
        delete(del);
        return head;
        
    }
};
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* temp = head ;
//         int count = 0;
//         while(temp!=nullptr){
//             count++;
//             temp=temp->next;
//         }
//         int deleten = count-n ;
//         if(count==n){
//             ListNode* newhead = head->next;
//             return newhead;
//         }
//         temp=head;
//         while(temp!=nullptr){
//            deleten--;
//            if(deleten==0){
//             break;
//            }
//            temp=temp->next;
//         }
//         ListNode* del = temp->next;
//         temp->next = temp->next->next;
//         delete(del);
//         return head;   
//     }
// };