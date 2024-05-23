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
    ListNode* middleNode(ListNode* head) {
       int count=0;
       ListNode* temp = head;
       ListNode* curr = head;
       while(temp)
       {
        count++;
        temp=temp->next;
       } 
        temp=head; // initiliaze temp back to head
        int mid = (count/2)+1;
        count=0;
        while(temp){
            mid=mid-1;
            if(mid==0){
                break;
            }else{
                temp=temp->next;
            }
        }
        return temp;
    }
};