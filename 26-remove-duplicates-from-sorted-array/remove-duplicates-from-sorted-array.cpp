class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> s;
        // for (auto it : nums) {
        //     s.insert(it);
        // }
        // int i=0;
        // for (auto it:s) {
        //     nums[i] = it;
        //     i++;
        // }

        // return s.size();

        // Optimal Solution
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};