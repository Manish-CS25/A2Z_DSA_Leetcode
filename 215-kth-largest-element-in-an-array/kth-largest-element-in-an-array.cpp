class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int kth_max;
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        for (int i = 0; i < k; i++) {
            kth_max = pq.top();
            pq.pop();
            
        }
        return kth_max;
    }
};