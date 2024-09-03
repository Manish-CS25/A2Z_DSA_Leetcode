class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;
        int ans = INT_MIN;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=1)
            c=0;
            else c++;
            
            ans = max(ans, c);
        }
        return ans;
        
    }
};