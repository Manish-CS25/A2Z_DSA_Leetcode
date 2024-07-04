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
class Solution{
    public:
         ListNode* mergeNodes(ListNode* head){
            if(!head->next) return nullptr;

            ListNode* ptr = head->next;
            int sum=0;
            while(ptr->val!=0)
            {
                sum+=ptr->val;
                ptr= ptr->next;
            }

            head->next->val= sum;

            head->next->next = mergeNodes(ptr);

            return head->next;
         }


};