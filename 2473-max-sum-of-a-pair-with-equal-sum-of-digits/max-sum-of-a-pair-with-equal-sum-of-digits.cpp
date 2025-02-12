class Solution {
public:
    int sum_of_digits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {

            int sd = sum_of_digits(nums[i]);

            mp[sd].push_back(nums[i]);
        }

        for (auto& it : mp) {
            vector<int> sn = it.second;
            if (sn.size() < 2)
                continue;
            priority_queue<int> pq;
            for (auto el : sn)
                pq.push(el);
            int sum = 0;
            sum += pq.top();
            pq.pop();
            sum += pq.top();
            ans = max(sum, ans);
        }
        return ans;
    }
};