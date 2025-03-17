class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        if (n % 2 == 1)
            return false;
        for (auto it : nums) {
            mp[it]++;
        }
        for (auto it : mp) {
            if (it.second % 2 == 1)
                return false;
        }
        return true;
    }
};