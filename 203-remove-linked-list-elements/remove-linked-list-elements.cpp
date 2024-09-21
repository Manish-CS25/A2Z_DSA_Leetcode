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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        return head;
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head;
        // ListNode* temp = dummy;
        // while (temp->next) {
        //     if (temp->next->val == val) {
        //         temp->next = temp->next->next;

        //     } else
        //         temp = temp->next;
        // }
        // return dummy->next;

        while(head!=NULL && head->val ==val) head = head->next;
                ListNode* temp = head;
        while (temp) {
            if (temp->next!=NULL && temp->next->val == val) {
                temp->next = temp->next->next;

            } else
                temp = temp->next;
        }
        return head;








    }
};