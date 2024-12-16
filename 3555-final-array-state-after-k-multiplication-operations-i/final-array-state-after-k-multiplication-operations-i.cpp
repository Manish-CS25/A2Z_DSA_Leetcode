class Solution {
public:
    int find_min(vector<int>& nums , int n){
        int mini = INT_MAX;
        int min_index;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini = nums[i];
                min_index = i;
            }
        }
        return min_index;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k){
            int index = find_min(nums , n);
            nums[index] =multiplier * nums[index];
            k--;
        }

        return nums;
    }
};