class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int less_than_zero= 0;
        int more_than_zero= 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                more_than_zero++;
            }else if(nums[i]<0){
                less_than_zero++;
            }
        }
        return max(more_than_zero,less_than_zero);
    }
};