// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         while(headB!=nullptr){
//             ListNode* temp = headA;
//             while(temp!=nullptr){
//                 if(temp == headB){
//                     return headB;
//                 }
//                 temp=temp->next;
//             }
//             headB=headB->next;
//         }
//         return NULL;
//     }
// };
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0 , l2=0 ;
        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;
        while(dummy1 != nullptr){
            l1++;
            dummy1=dummy1->next;
        }
        while(dummy2 != nullptr){
            l2++;
            dummy2=dummy2->next;
        }
        int len = abs( l1-l2);
        dummy1=headA;
        dummy2=headB;
        if(l1>l2){
            while(len--) headA=headA->next;
        }else {
           while(len--) headB=headB->next;
        }
        while(headA!=nullptr){
            if(headA==headB) return headA;
            headB=headB->next;
            headA=headA->next;
        }
        return NULL;
    }
};