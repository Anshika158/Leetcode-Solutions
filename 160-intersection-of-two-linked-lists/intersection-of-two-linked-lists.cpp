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
    //   while(headB!=NULL){
    //     ListNode* temp = headA;
    //     while(temp){
    //         if(temp==headB){
    //             return headB;
    //         }
    //         else{
    //             temp=temp->next;
    //         }
    //     }
    //     headB=headB->next;
    
    //   }
    //   return NULL;

//2nd approach Hashing
    unordered_set<ListNode*> st;
    ListNode* temp=headA;
    while(headA){
        st.insert(headA);
        headA=headA->next;
    }
    while(headB){
        if(st.find(headB)!=st.end()){
            return headB;
        }
        headB=headB->next;
    }
    return NULL;
    }
};