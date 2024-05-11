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
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* temp=head;
        ListNode* last= NULL;
        ListNode* next1= NULL;
        while(temp!=NULL){
            next1 = temp->next;
            temp->next =last;
            last =temp;
            temp =next1;
            
        }
       return last;
       
    }
};