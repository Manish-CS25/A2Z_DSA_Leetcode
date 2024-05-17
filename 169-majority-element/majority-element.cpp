class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Moore's Voting algo
        int me;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                me = nums[i];
                count = 1;
            } else if (me == nums[i]) {
                count++;
            } else
                count--;
        }

        // verify the element we got is majority element or not
        int count1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (me == nums[i])
                count1++;
        }
        if (count1 > (nums.size() / 2))
            return me;
        else
            return -1;
    }
};