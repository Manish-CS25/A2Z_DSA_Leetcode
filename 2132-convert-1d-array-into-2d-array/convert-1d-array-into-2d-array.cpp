class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        vector<vector<int>> ans(m , vector<int> (n));

        if((m*n) != s)
        return {};
        int start = 0;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[start +j];
            }
            start+=n;
        }
      return ans;
    }
};