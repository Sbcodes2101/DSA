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
    ListNode* reverseList(ListNode* head) {
        // brute force approach
        // ListNode* temp = head;
        // stack<int> st;
        // while(temp != NULL){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp=head;
        // while(!st.empty()){
        //     int ele=st.top();
        //     st.pop();
        //     temp->val=ele;
        //     temp=temp->next;
        // }
        // return head;

        ListNode* temp = head;
        ListNode* forw = head;
        ListNode* prev = NULL;

        while(forw !=NULL){
            forw = forw->next;
            temp->next = prev;
            prev=temp;
            temp=forw;
        }
        return prev;
    }
};