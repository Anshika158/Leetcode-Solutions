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
    ListNode* reverse(ListNode* head){
        // BASE CASE
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second){
            if(first->val != second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};
































// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverse(ListNode* head){
//         if(head==nullptr || head->next==nullptr){
//             return head;
//         }
//         ListNode* newhead = reverse(head->next);
//         ListNode* front = head->next;
//         front->next=head;
//         head->next=nullptr;
//         return newhead;
//     }
//     bool isPalindrome(ListNode* head) {
//         // stack<ListNode*> st;
//         // ListNode* temp = head;
//         // while(temp){
//         //     st.push(temp);
//         //     temp=temp->next;
//         // }
//         // while(head){
//         //     if(st.top()->val != head->val){
//         //         return false;
//         //     }
//         //     st.pop();
//         //     head=head->next;
//         // }
//         // return true;

//         if(head==nullptr || head->next==nullptr){
//             return true;
//         }
//         ListNode* slow=head;
//         ListNode* fast=head;
//         while(fast->next!=nullptr && fast->next->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         ListNode* newhead = reverse(slow->next);
//         ListNode* first = head;
//         ListNode* second = newhead;
//         while(second){
//             if(first->val != second->val){
//                 return false;
//             }
//             first=first->next;
//             second=second->next;
//         }
//         return true;
//     }
// };