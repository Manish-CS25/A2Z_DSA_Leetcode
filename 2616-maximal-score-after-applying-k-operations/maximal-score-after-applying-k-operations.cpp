class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }

        long long score = 0;

        while (k) {
            int maxVal = pq.top();
            score += maxVal;
            pq.pop();
            pq.push(ceil((double)maxVal / 3));
            k--;
        }

        return score;
    }
};