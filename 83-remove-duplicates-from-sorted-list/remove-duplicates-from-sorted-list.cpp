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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        set<int> arr;
        while (head) {
            arr.insert(head->val);
            head = head->next;
        }
        int i = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* prev = ans;
        for(auto it:arr){
            prev->next = new ListNode(it);
            prev = prev->next;
        }

        return ans->next;
    }
};