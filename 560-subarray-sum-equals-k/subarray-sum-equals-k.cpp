// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n=nums.size(),res=0;
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
//                 if(sum==k){
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };

/// =========Optimal Way ===========

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        long long sum = 0;
        unordered_map<long long, int> prefix; // To store the frequency of prefix sums
        
        prefix[0] = 1; // Initialize with prefix sum 0 occurring once (important for subarrays starting from index 0)

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Check if there's a prefix sum that satisfies sum - k
            long long rem = sum - k;
            if (prefix.find(rem) != prefix.end()) {
                cnt += prefix[rem];
            }

            // Update the prefix sum frequency
            prefix[sum]++;
        }

        return cnt;
    }
};
