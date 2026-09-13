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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL) {
            int addition = 0;
            if(temp1!=NULL) addition += temp1->val;
            if(temp2!=NULL) addition += temp2->val;
            addition += carry;

            if (addition < 10) {
                ListNode* newnode = new ListNode(addition);
                temp->next = newnode;
                temp = temp->next;
                carry = 0;
            }

            else {
                ListNode* newNode = new ListNode(addition % 10);
                carry = addition / 10;
                temp->next = newNode;
                temp = temp->next;
            }

            if(temp1 != NULL) temp1 = temp1->next;
            if(temp2 != NULL) temp2 = temp2->next;
        }


        if(carry>0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = temp->next;
        }

        return dummy->next;
    }
};