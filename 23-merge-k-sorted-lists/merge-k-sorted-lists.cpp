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

// -------------Brute Force Approach ---------------

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<int> arr;
//         for (int i = 0; i < lists.size(); i++) {
//             ListNode* temp = lists[i];
//             while (temp != NULL) {
//                 arr.push_back(temp->val);
//                 temp = temp->next;
//             }
//         }
//         sort(arr.begin(), arr.end());

//         if (arr.empty()) {
//             return nullptr;
//         }

//         ListNode* head = new ListNode(arr[0]);
//         ListNode* current = head;

//         for (size_t i = 1; i < arr.size(); ++i) {
//             current->next = new ListNode(arr[i]);
//             current = current->next;
//         }

//         return head;
//     }
// };

///----------------In place merging by merge 2 lists at a
/// time------------------------

// class Solution {
// public:
//     ListNode* mergeTwoList(ListNode* head1, ListNode* head2)
//     {
//         if (!head1)
//             return head2;
//         if (!head2)
//             return head1;
//         ListNode* ans = new ListNode(-1);
//         ListNode* ptr = ans;
//         while (head1 && head2)
//         {
//             if (head1->val < head2->val)
//             {
//                 ptr->next = head1;
//                 ptr = ptr->next;
//                 head1 = head1->next;
//             }
//             else
//             {
//                 ptr->next = head2;
//                 ptr = ptr->next;
//                 head2 = head2->next;
//             }
//         }
//         while (head1)
//         {
//             ptr->next = head1;
//             ptr = ptr->next;
//             head1 = head1->next;
//         }
//         while (head2)
//         {
//             ptr->next = head2;
//             ptr = ptr->next;
//             head2 = head2->next;
//         }
//         return ans->next;
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists)
//     {
//         if (lists.size() == 0)
//             return NULL;
//         ListNode* head1 = lists[0];
//         for (int i = 1; i < lists.size(); i++)
//             head1 = mergeTwoList(head1, lists[i]);
//         return head1;
//     }
// };

// ======================Using Priority Queue =======================

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dnode = new ListNode(-1);
        ListNode* temp = dnode;
        while (!pq.empty()) {
            pair<int, ListNode*> p = pq.top();

            
            pq.pop();
            if (p.second->next) {
                pq.push({p.second->next->val, p.second->next});
            }
            temp->next = p.second;
            temp = temp->next;
        }
        return dnode->next;
    }
};
