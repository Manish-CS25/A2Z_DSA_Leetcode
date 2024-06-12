class Solution {
private:
    void DFS(int node, vector<int> AdjList[], vector<int>& vis) {

        
        for (auto it : AdjList[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                DFS(it, AdjList, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // change AdjMatrix to AdjList
        int count = 0;

        int V = isConnected.size();
        // vector<vector<int>> AdjList[V];
        vector<int> AdjList[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    AdjList[i].push_back(j);
                    AdjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
         for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                count++;
                DFS(i, AdjList, vis);
            }
        }
        return count;
    }
};