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
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*,Node*> mp;
        Node* dummy = new Node(0);
        Node* temp1 = dummy;

        while(temp != NULL){
            Node* newnode = new Node(temp->val);
            temp1->next = newnode;
            temp1 = temp1->next;
            mp[temp] = newnode;
            temp = temp->next;
        }

        temp=head;
        temp1 = dummy->next;

        while(temp!=NULL){
            temp1->random = mp[temp->random];
            temp=temp->next;
            temp1=temp1->next;
        }

        return dummy->next;
    }
};