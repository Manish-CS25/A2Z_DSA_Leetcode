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

        int size = 0;
        ListNode* temp = head;

        while (temp) {
            size++;
            temp = temp->next;
        }

        if (size == 1)
            return NULL;

        int k = size - n;
        int i = 1;
        temp = head;

        if(k==0){
            return head->next;
        }

        while (head) {

            if (i == k) {
                ListNode* delNode = head->next;
                head->next =delNode->next;
                delNode->next = NULL;
            }
            i++;
            head = head->next;
        }

        return temp;
    }
};