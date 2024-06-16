class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long missing = 1;
        int i = 0;
        long long patch = 0;

        while (missing <= n) {

            //check missing is less than nums[i] or not 
            if(i< nums.size() && nums[i]<=missing){
                missing = missing + nums[i];
                i++;

            }

            // when missing is less than nums[i] that means missing is not covered and we patch it and check further
            else {
                missing += missing;
                patch++;
            }
        }

        return patch;
    }
};