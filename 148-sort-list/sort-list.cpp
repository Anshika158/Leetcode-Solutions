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
    ListNode* sortList(ListNode* head) {
     vector<int> arr;
     if(head==NULL || head->next == NULL){
        return head;
     }
     ListNode* temp = head;

     
    while(temp){
        arr.push_back(temp->val);
        temp=temp->next;
     }
     sort(arr.begin() , arr.end());
     //int count = arr.size();

    //  temp= head;
    //  while(temp){
    //     for(int i =0 ; i<count ; i++){
    //         temp->val=arr[i];
    //         temp=temp->next;
    //     }  
    //  }

    // temp = head;
    // int i = 0 ;
    // while(temp){
    //     // first it will store the value then it will increment i value;
    //     temp->val = arr[i++];
    //     temp= temp->next;

    // }
    //  return head;

        temp=head;
        for(int it : arr){
            temp->val=arr;
            temp=temp->next;
        }
        return head;
    }
};
