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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // brute force approach
        // ListNode* temp=head;
        // int len=0;
        // if(head==NULL || head->next==NULL) return NULL;
        // while(temp != NULL){
        //     temp = temp->next;
        //      len++;
        // }

        // if (n == len) {
        //     ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }

        // temp=head;
        // int steps = len-n-1;
        // while(steps != 0){
        //     temp=temp->next;
        //     steps--;
        // }

        // temp->next = temp->next->next;
        // return head;

        // optimal approach using slow and fast
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        if(fast == NULL) return head->next;

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};