class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : nums) {
            pq.push(it);
        }

        for (int i = 0; i < nums.size() - 1; i += 2) {
            int alice = pq.top();
            pq.pop();
            int bob = pq.top();
            pq.pop();
            nums[i] = bob;
            nums[i + 1] = alice;
        }
        return nums;
    }
};