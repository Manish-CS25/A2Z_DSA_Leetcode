class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long missing = 1;
        int i = 0;
        long long patch = 0;

        while (missing <= n) {
            if(i< nums.size() && nums[i]<=missing){
                missing = missing + nums[i];
                i++;

            }
            else {
                missing += missing;
                patch++;
            }
        }

        return patch;
    }
};