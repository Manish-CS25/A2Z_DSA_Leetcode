class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;

        // first of all push all elements to the priority queue
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }

        for (int i = 0; i < k - 1; i++) {
            // because priority queue keep max elememt on top so
            // we will pop k-1 element
            pq.pop();
        }
        // now top of pq will be kth max element
        return pq.top();
    }
};