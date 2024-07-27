class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
         static constexpr int INF = 1e9;
        vector<vector<long long>> dp(26,vector<long long>(26,INF));
        for(int i=0;i<26;i++)dp[i][i]=0;
        for(int i=0;i<original.size();i++){
            if(dp[original[i]-'a'][changed[i]-'a']>cost[i]){
                dp[original[i]-'a'][changed[i]-'a']=cost[i];
            }
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dp[i][k]<INF && dp[k][j]<INF)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(dp[source[i]-'a'][target[i]-'a']==INF)return -1;
                ans+=dp[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};