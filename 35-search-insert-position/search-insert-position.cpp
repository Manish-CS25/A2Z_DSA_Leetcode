class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int index = 0;
        

        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid]) {
                l = mid + 1;
                index = mid+1;
            } else {
                h = mid - 1;
                index = mid;
            }
        }

        return index;
    }
};