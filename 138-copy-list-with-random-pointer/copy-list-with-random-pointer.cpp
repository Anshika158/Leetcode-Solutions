/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertBetween(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy = new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
    }
    void connect(Node* head){
        Node* temp = head;
        while(temp!=nullptr){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }else{
                copyNode->random=nullptr;
            }
            temp=temp->next->next;
        }
    }
    Node* deepList(Node* head){
        Node* dummy = new Node(-1);
        Node* temp=head;
        Node* res= dummy;
        while(temp!=nullptr){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;

        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
       if(head==nullptr){
        return nullptr;
       }
       insertBetween(head);
       connect(head);
       return deepList(head);
    }
};