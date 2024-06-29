class Solution {

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), graph(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
        }

        // Doing dfs to know list of ancestor
        for (int i = 0; i < n; i++) {
            vector<bool> vs(n, false);
            int p = i;
            int c = i;
            dfs(graph, p, c, ans, vs);
        }
        // Sorted the list of ancestor , corresponding to every node
        for (int i = 0; i < n; i++) {
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& graph, int parent, int curr,
             vector<vector<int>>& ans, vector<bool>& vs) {

        vs[curr] = true;
        for (int childrn : graph[curr]) {
            if (!vs[childrn]) {
                ans[childrn].push_back(parent);
                dfs(graph, parent, childrn, ans, vs);
            }
        }
    }
};