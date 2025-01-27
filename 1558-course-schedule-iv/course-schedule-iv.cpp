class Solution {
public:
    bool dfs(int s , int t , vector<vector<int>> &adj, vector<int> &vis ){
        if(s==t) return true;
        vis[s]=1;
        for(auto &it:adj[s]){
            if(vis[it]!=1 && dfs(it , t , adj , vis)) return true;
            
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(numCourses);
        vector<bool> ans;
        int n = prerequisites.size();
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int m = queries.size();
        for(int i=0;i<m;i++){
            int s = queries[i][0];
            int t = queries[i][1];
            vector<int> vis(numCourses , 0);

            if(dfs(s , t , adj , vis)){
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
       return ans;
    }
};