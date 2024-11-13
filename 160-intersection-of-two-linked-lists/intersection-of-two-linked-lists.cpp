/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans = NULL;

        unordered_map<ListNode*  , int> mp;

        while(headA){
            mp[headA]=1;
            headA= headA->next;
        }

        while(headB){
            if(mp.find(headB)!=mp.end()){
                return headB;
                break;
            }
            headB = headB->next;
        }

        return ans;


    }
};