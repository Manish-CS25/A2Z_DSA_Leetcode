class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int cnt = 0;

        // BruteForce Gives TLE

        // for (int i = 0; i < nums.size(); i++) {
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         sum += nums[j];
        //         cout << i;
        //         if (sum == goal) {
        //             cnt++;
        //             cout << j;
        //         }
        //     }
        // }

        // optimal

        int n = nums.size();
        unordered_map<int , int>  mpp;
        int sum =0;
        int result =0;

        mpp[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mpp.find(sum - goal)!=mpp.end()){
                result += mpp[sum - goal];

            }
            mpp[sum]++;
        }

        return result;
    }
};