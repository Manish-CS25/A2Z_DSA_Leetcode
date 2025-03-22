class Solution {
public:
void bfs(int i, unordered_map<int,vector<int>>& adj, vector<bool>& visited, int& v, int& e){
    queue<int>q;
    q.push(i);
    visited[i]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        v++;
        e+=adj[curr].size();
        for(auto& neighbour:adj[curr]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
}
// void dfs(int i, unordered_map<int,vector<int>>& adj, vector<bool>& visited, int& v, int& e){
//     visited[i]=true;
//     v++;
//     e+=adj[i].size();
//     for(auto& neighbour:adj[i]){
//         if(!visited[neighbour]){
//             dfs(neighbour,adj,visited,v,e);
//         }
//     }
// }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        int result=0;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            int v=0;
            int e=0;
            bfs(i,adj,visited,v,e);
            if((v*(v-1)) == e){
                result++;
            }
        }
        return result;
    }
};