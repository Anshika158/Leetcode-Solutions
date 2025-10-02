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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while((first!=nullptr || second!=nullptr)|| carry){
            int sum=0;
            if(first!=nullptr){
                sum+=first->val;
                first=first->next;
            }
            if(second!=nullptr){
                sum+=second->val;
                second=second->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};
