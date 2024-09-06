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
    bool bs(vector<int>& nums , int key){
        int l =0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==key)
            return true;
            else if(key>nums[mid])
                l=mid+1;
            else
                h=mid-1;
      }
        return false;
        
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        ListNode* temp = head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(temp){
            int key = temp->val;
            if(bs(nums, key))
            { 
              prev->next = temp->next;     
            }
            else prev = temp;
            temp = temp->next;
            
       } 
        ListNode * new_head = dummy->next;
        delete dummy;
        
        return new_head;
        
    }
};