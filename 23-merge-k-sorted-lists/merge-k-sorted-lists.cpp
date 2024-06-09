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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(), arr.end());

        if (arr.empty()) {
            return nullptr;
        }

        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }

        return head;
    }
};