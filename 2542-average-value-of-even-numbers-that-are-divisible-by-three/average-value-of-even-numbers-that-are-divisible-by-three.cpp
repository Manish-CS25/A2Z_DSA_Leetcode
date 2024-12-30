class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ans;
        int sum=0;
        int cnt=0;
        for(auto it:nums){
            if(it%3==0 && it%2==0){
                sum+=it;
                cnt++;
            }
        }
        if (cnt >= 1)
        return sum / cnt;

        return 0;
        
    }
};