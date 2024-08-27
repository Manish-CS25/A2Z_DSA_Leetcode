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

// == == == == == == == == == == == My Approach-- but it gives bit overflow ==


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         if (!l1 && !l2)
//             return NULL;
//         long long val_l1 = 0;
//         int i = 0;
//         while (l1) {
//             val_l1 += pow(10, i) * (l1->val);
//             l1 = l1->next;
//             i++;
//         }
//         cout << val_l1;
//         long long val_l2 = 0;
//         i = 0;
//         while (l2) {
//             val_l2 += pow(10, i) * (l2->val);
//             l2 = l2->next;
//             i++;
//         }

//         long long sum = val_l1 + val_l2;
//         // cout << sum;
//         ListNode* ans = new ListNode(sum % 10);
//         ListNode* temp = ans;
//         sum = sum / 10;
//         while (sum) {
//             int val_a = sum % 10;
//             sum = sum / 10;
//             ListNode* new_node = new ListNode(val_a);
//             temp->next = new_node;
//             temp = temp->next;
//         }

//         return ans;
//     }
// };
//  == == == == == == == == == == === Optimal approach == == == == == == ==

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy =
            new ListNode(0);       // Dummy node to help in list construction
        ListNode* current = dummy; // Pointer to construct the new list
        int carry = 0; // To store the carry-over during the addition

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry from the previous step

            if (l1 != nullptr) {
                sum += l1->val; // Add l1's value if it exists
                l1 = l1->next;  // Move to the next node in l1
            }

            if (l2 != nullptr) {
                sum += l2->val; // Add l2's value if it exists
                l2 = l2->next;  // Move to the next node in l2
            }

            carry = sum / 10; // Calculate new carry
            current->next = new ListNode(
                sum % 10); // Create a new node with the current digit

            current = current->next; // Move to the next node in the result list
        }

        return dummy->next; // Return the result list, skipping the dummy node
    }
};
