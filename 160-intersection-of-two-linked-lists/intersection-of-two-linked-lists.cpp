/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         ListNode* ans = NULL;

//         unordered_map<ListNode*, int> mp;

//         while (headA) {
//             mp[headA] = 1;
//             headA = headA->next;
//         }

//         while (headB) {
//             if (mp.find(headB) != mp.end()) {
//                 return headB;
//                 break;
//             }
//             headB = headB->next;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ans = NULL;

        int size1 = 0, size2 = 0;

        if (!headA || !headB)
            return ans;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA) {
            size1++;
            tempA = tempA->next;
        }

        while (tempB) {
            size2++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if (size1 > size2) {
            int diff = size1 - size2;
            while (diff--) {
                tempA = tempA->next;
            }
        } else if (size2 > size1) {
            int diff = size2 - size1;
            while (diff--) {
                tempB = tempB->next;
            }
        }

        while (tempA && tempB) {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return ans;
    }
};