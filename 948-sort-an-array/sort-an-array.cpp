class Solution {
public:
    void stlSort(vector<int>& nums) { sort(nums.begin(), nums.end()); }

    vector<int> sortArray(vector<int>& nums) {
        stlSort(nums);
        return nums;
    }
};