class Solution {
public:
    int nC2(int n){
        return (n*(n-1)/2);
    }
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                map[nums[i]*nums[j]]++;
            }
        }

        int count = 0;
        for(auto i = map.begin(); i != map.end(); i++){
            if(i->second > 1){
                count += 8*(nC2(i->second));
            }
        }

        return count;
    }
};