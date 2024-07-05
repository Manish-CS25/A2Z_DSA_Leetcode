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
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         ListNode* prev = head;
//         // vector<int> ans(2) = {-1, -1};
//         int min_d = INT_MAX, prev_i = INT_MIN, first_i = -1;
//         ListNode* temp = head->next;
//         int i = 1;
//         while (temp->next != NULL) {

//             if ((prev->val < temp->val && temp->val > temp->next->val) ||
//                 (prev->val > temp->val && temp->val < temp->next->val)) {
//                 if (prev_i != INT_MIN) {
//                     min_d = min(min_d, i - prev_i);
//                 }
//                 if (first_i == -1) {
//                     first_i = i;
//                 }
//                 prev_i = i;
//             }
//             prev = temp;
//             if (min_d == INT_MAX) {
//                 return {-1, -1};
//             }
//         }

//         return {min_d, prev_i - first_i};
//     }
// };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev=head;
        head=head->next;
        int i=1;
        vector<int> index;
        while(head->next){
            if((prev->val < head->val and head->val > head->next->val) ||( prev->val > head->val and head->val < head->next->val)){
                index.push_back(i);
            }
            prev=head;
            head=head->next;
            i++;
        }
        if(index.size() < 2) return {-1,-1};
        
        int mindist=INT_MAX;
        for(int i=0;i<index.size()-1;i++){
            mindist=min(index[i+1]-index[i],mindist);
        }
        return {mindist,index.back()-index[0]};
    }
};