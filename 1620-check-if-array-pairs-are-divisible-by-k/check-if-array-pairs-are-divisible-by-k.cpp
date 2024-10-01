class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> remCount;

        for(auto a : arr) remCount[(a % k + k) % k]++;

        for(auto a : arr) {
            int rem = (a % k + k) % k;

            if(rem == 0) {
                if(remCount[rem] % 2 == 1) return false;
            } 

            else if(remCount[rem] != remCount[k - rem]) {
                return false;
            }
            
        }

        return true;
    }
};