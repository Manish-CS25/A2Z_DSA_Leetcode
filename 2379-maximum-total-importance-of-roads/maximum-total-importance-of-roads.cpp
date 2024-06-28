class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        vector<int> cities(n);
        for (int i = 0; i < n; ++i) {
            cities[i] = i;
        }
        
        sort(cities.begin(), cities.end(), [&degree](int a, int b) {
            return degree[a] > degree[b];
        });
        
        vector<int> values(n);
        int currentValue = n;
        for (int city : cities) {
            values[city] = currentValue--;
        }
        
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += values[road[0]] + values[road[1]];
        }
        
        return totalImportance;
    }
};