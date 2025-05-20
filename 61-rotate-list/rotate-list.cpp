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
        if(head==nullptr){
            return 0;
        }
        ListNode* temp = head;
        int count=1;
        while(temp->next!=nullptr){
            count++;
            temp=temp->next;
        }
        k = k%count;
        if(k==0){
            return head;
        }
        temp->next=head;
        int end = count-k;
        while(end!=0){
            temp=temp->next;
            end--;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};