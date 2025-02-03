class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
         int n = nums.size();
        int maxCount = 1;
        int counti = 1;
        int countd = 1;
        for(int i = 0; i<n-1; i++){
            if(nums[i]<nums[i+1]){
                countd = 1;
                counti++;
            }
            else if(nums[i]>nums[i+1]){
                counti = 1;
                countd++;
            }
            else{
                counti = 1;
                countd = 1;
            }
            maxCount = max(maxCount,max(counti,countd));
        }
        return maxCount;
    }
};