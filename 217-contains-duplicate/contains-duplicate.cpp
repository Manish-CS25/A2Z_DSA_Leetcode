// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int > SET;

//         for(auto it:nums){
//             if(SET.find(it)!=SET.end()){
//                 return true;
//             }
//             SET.insert(it);
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};