class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<int> ans;
        
        // vector<vector<int>> subarr;
        for(int i=0; i< n-k+1;i++){    
            bool flag=false;

            for(int j=0;j<k-1;j++){
                    if(nums[i+j]>=nums[i+j+1]  || abs(nums[i+j]-nums[i+j+1]) !=1 ){
                    ans.push_back(-1);
                    flag=true;
                    break;
                    }
            }

      
            if(!flag)
            ans.push_back(nums[i+k-1]);
            
            }
        return ans;
        
    }
};