class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int > SET;

        for(auto it:nums){
            if(SET.find(it)!=SET.end()){
                return true;
            }
            SET.insert(it);
        }

        return false;
    }
};