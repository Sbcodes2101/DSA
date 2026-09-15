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
    ListNode* reverse(ListNode* head,int k){
        ListNode* temp = head;
        int curr=k;

        while(curr--){
            if(temp == NULL) return head;
            temp = temp->next;
        }

        ListNode* next_group = temp;

        temp = head;
        ListNode* prev = NULL;

        while(temp!=next_group){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }

        head->next = reverse(next_group,k);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
         return reverse(head,k);
    }
};