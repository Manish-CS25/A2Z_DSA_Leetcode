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
// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         ListNode* new_Head;
//         int sum = 0;
//         ListNode* temp = head->next;
//         int i = 0;
//         ListNode* temp3;
//         while (temp != NULL) {
//             if (temp->val != 0)
//                 sum += temp->val;
//             else {

//                 ListNode* tmp2 = new ListNode(sum);
//                 if (i == 0) {
//                     new_Head = tmp2;
//                     temp3 = new_Head;
//                     i++;
//                 }

//                 else {
//                     temp3->next = tmp2;
//                     temp3 = temp3->next;
//                 }

//                 sum = 0;
//             }
//             temp = temp->next;
//         }
//         return new_Head;
//     }
// };

// =============Recursive Solution ===============
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // BASE CASE -> if we have a single zero, simply return null
        if (!head->next)
            return nullptr;

        // fetch sum from current 0 to next 0
        ListNode* ptr = head->next;
        int sum = 0;
        while (ptr->val != 0) {
            sum += ptr->val;
            ptr = ptr->next;
        }
        // assign sum on the first node between nodes having value 0.
        head->next->val = sum;
        // call and get the answer and connect the answer to next of head->next

        head->next->next = mergeNodes(ptr);
        // return head->next..=> new head
        return head->next;
    }
};