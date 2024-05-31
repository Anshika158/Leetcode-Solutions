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
         map<ListNode* , int > map;
      ListNode* temp=head;
      while(temp!=NULL){
        if(map.find(temp)!=map.end()){
            return true;
        }
        map[temp]=1;
        temp=temp->next;
      }  
      return false;
    }
};