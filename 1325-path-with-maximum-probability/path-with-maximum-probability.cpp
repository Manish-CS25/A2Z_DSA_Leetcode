class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int s, int e) {
        vector<vector<pair<int, double>>> adj(n);
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> prob(n, 0);
        priority_queue<pair<double, int>> pq;
        prob[s] = 1.0;
        pq.push({1.0, s});
        while (!pq.empty()) {
            double curr_prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                double edge_prob  = it.second;
                int adj_node = it.first;
                if (curr_prob * edge_prob > prob[adj_node]) {
                    prob[adj_node] = curr_prob * edge_prob;
                    pq.push({prob[adj_node], adj_node});
                }
            }
        }
        return prob[e];
    }
};