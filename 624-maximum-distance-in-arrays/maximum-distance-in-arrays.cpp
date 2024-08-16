class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n = arr.size();
        int mini=arr[0][0], maxi=arr[0][arr[0].size()-1];
        int max_d=0;
        
        for(int i=1; i<n;i++){

            max_d= max(max_d , abs(arr[i].back()-mini));
            max_d= max(max_d , abs(arr[i][0]-maxi));

            mini = min(mini, arr[i][0]);
            maxi = max(maxi , arr[i].back());

            





        }

        return max_d;
        
    }
};