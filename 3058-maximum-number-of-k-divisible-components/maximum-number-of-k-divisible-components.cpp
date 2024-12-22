class Solution {
public:
    int dfs(int curr_node, int parent, vector<vector<int>>& adj,
            vector<int>& values, int k, int &cnt) {
        long long sum = values[curr_node]; // Start with the node's value

        // Traverse all the child nodes (neighbors)
        for (auto ng_node : adj[curr_node]) {
            if (ng_node != parent) {  // Avoid going back to the parent
                sum += dfs(ng_node, curr_node, adj, values, k, cnt);  // Add sum of child subtrees
            }
        }
        

        sum %=k;
        // Check if the sum of the current subtree is divisible by k
        if (sum == 0) {
            cnt++;  // This subtree is a valid component

        }

        // Return the sum to the parent node if it's not divisible by k
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        // Build the adjacency list from the edges
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int cnt = 0;
        dfs(0, -1, adj, values, k, cnt);  // Start DFS from node 0

        return cnt;  // Return the number of valid components divisible by k
    }
};
