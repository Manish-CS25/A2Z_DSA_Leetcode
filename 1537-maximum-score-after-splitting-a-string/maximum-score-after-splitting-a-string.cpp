class Solution {
public:
    int maxScore(string s) {
        int zeros  =0;
        int ones = 0;
        int n = s.size();
        vector<pair<int, int>> p(n);
        int i=0;
        for(auto &it:s){ 
            if(it=='0') zeros++;
            if(it=='1') ones++;

            p[i++]={zeros , ones};
            // cout<<ones<<zeros;
        }
        int ans = 0;
        for(int i=0; i<n-1;i++){
           
           ans = max(p[i].first + ones-p[i].second , ans);
        }
        
        return ans;
    }
};