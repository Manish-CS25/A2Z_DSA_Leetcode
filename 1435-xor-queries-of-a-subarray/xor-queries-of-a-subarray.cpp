class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for (int i = 1; i < n; i++) 
            arr[i] ^= arr[i - 1];
        

        vector<int> ans;

        for (auto it : queries) {
            int s = it[0];
            int e = it[1];
             
            ans.push_back(arr[e] ^ ((s-1>=0)? arr[s-1]:0));
        }

        return ans;
    }
};