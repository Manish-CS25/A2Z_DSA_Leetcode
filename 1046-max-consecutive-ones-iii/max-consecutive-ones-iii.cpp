class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int L , R , maxlen, zeros;
        L = R = maxlen = zeros = 0;

        while(R<nums.size()){
            if(nums[R]==0)
            zeros++;
            if(zeros>k){
                if(nums[L]==0)
                zeros--;
                L++;
            }
            if(zeros<=k)
            {
                
                maxlen = max(R - L + 1, maxlen);
            }
            R++;

        }
        return maxlen;
    }
};