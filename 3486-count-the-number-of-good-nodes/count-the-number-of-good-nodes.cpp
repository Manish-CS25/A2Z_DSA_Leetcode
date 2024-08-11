class Solution {
    int cnt;

private:
    int dfs(vector<vector<int>>& adj, int node, int parent) {
        int total = 0;
        int subTree = -1;
        bool isValid = true;

        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            int curr = dfs(adj, it, node);
            if (subTree == -1) {
                subTree = curr;
            } else if (subTree != curr) {
                isValid = false;
            }
            total += curr;
        }
        if (isValid) {
            cnt++;
        }

        return total + 1;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        cnt = 0;
        dfs(adj, 0, -1);
        return cnt;
    }
};