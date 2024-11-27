class Solution {
public:
    int Dijkstra(vector<vector<int>>& adj, int n) {

        priority_queue<pair<int, int> ,  vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n ,1e9);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (auto adjNode : adj[node]) {
                if (dis + 1 < dist[adjNode]) {
                    dist[adjNode] = dis + 1;
                    pq.push({dis+1, adjNode});
                }
            }
        }

        return dist[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        adj[0].push_back(1);
        // adj[n - 1].push_back(n - 2);

        vector<int> Result(queries.size());

        for (int i = 1; i < n - 1; i++) {
            // adj[i].push_back(i - 1);
            adj[i].push_back(i + 1);
        }

        for (int i = 0; i < queries.size(); i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            // adj[queries[i][1]].push_back(queries[i][0]);

            int ans = Dijkstra(adj, n);
            Result[i] = ans;
        }

        return Result;
    }
};