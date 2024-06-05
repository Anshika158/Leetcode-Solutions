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

// //2nd approach Hashing
//     unordered_set<ListNode*> st;
//     ListNode* temp=headA;
//     while(headA){
//         st.insert(headA);
//         headA=headA->next;
//     }
//     while(headB){
//         if(st.find(headB)!=st.end()){
//             return headB;
//         }
//         headB=headB->next;
//     }
//     return NULL;

int countA = 0;
int countB = 0 ;
ListNode* tempA = headA;
ListNode* tempB = headB;
while(tempA){
    countA++;
    tempA=tempA->next;
}
while(tempB){
    countB++;
    tempB=tempB->next;
}
int diff= abs(countA-countB);
tempA=headA;
tempB=headB;
    if(countA>countB){
    while(diff>0){
     
    tempA=tempA->next;
       diff--;
    }
    }else{
        while(diff>0){
           
            tempB=tempB->next;
             diff--;
        }
    }

while (tempA && tempB && tempA != tempB) {
    tempA = tempA->next;
    tempB = tempB->next;
}

// If tempA and tempB are equal, it means there's an intersection
if (tempA == tempB) {
    return tempA;
}

return NULL;

    }
};