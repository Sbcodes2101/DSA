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
    ListNode* reverse(ListNode* newNode){
        ListNode* prev = NULL;
        ListNode* temp = newNode;

        while(temp!=NULL){
            ListNode* nxtNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxtNode;
        }

        return prev;
    }

    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL && temp2 != NULL){
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;

            temp1->next = temp2;
            temp2->next = next1;

            temp1 = next1;
            temp2 = next2;
        }


        return list1;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = NULL;

        ListNode* newHead = reverse(temp);

        ListNode* temp1 = merge(head,newHead);
        head = temp1;
        return;
    }
};