class Solution {
public:
    void sortColors(vector<int>& nums) {


        /*The Dutch National Flag algorithm, also known as 3-way partitioning, is an algorithm for sorting an array containing three distinct values. 
        The algorithm was designed to solve the problem of sorting an array containing only 0s, 1s, and 2s, which is similar to the problem in the given question.
        */

        int low =0, mid =0, high = nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;

            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};