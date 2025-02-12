class Solution {
public:
    int sum_of_digits(int num){
        int sum =0;
        while(num){
            sum+= num%10;
            num/=10;
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

        for(auto &it:mp){
              vector<int> sn = it.second;
              if(sn.size()<2) continue;
              sort(sn.begin() , sn.end());
              int sz = sn.size();
              ans = max(sn[sz-1]+sn[sz-2] , ans);
        }
        return ans;
    }
};