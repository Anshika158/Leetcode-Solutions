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
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        unordered_set<ListNode*> st;
        ListNode* temp= head;
        while(temp!=nullptr){
            if(st.find(temp) !=st.end()){
               return true;
            }
            st.insert(temp);
            temp=temp->next;
            
        }

    return false;
    }
};