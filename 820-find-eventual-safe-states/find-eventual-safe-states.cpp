class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> ans;
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                revAdj[graph[i][j]].push_back(i);
                ind[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto it : revAdj[node]) {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};