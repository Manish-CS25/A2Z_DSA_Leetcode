class Solution {
public:
    bool bfs(int s, int d, vector<int>& vis, vector<vector<int>>& adj,
             queue<int>& q) {
        vis[s] = 1;
        //    q.push(s);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == d)
                return true;
            for (auto it : adj[node]) {
                if (vis[it] != 1) {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }




    bool validPath(int n, vector<vector<int>>& edges, int s,
                   int d) {

    vector<vector<int>> adj(n);
   int m = edges.size();
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(n, 0);
    queue<int> q;
    q.push(s);

    return bfs(s, d, vis, adj, q);
}
}
;