class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        int ones = count(nums.begin()  , nums.end() , 1);
        if(ones==0 || ones == n)
            return 0;
        int window_size = ones;
        int zero=0;
        
        for(int i=0; i< window_size;i++){
            if(nums[i]==0)
                zero++;
            
        }
        
        int minZero = zero;
        int start = 0;
        int end = window_size-1;
        while(start<n){
            if(nums[start]==0)
            zero--;
            start++;
            end++;
            if(nums[end%n]==0)
            zero++;

            minZero = min(minZero , zero);
        }

        
        return minZero;
    }
};