class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // vector<int> degree(n, 0);

        // for (const auto& road : roads) {
        //     degree[road[0]]++;
        //     degree[road[1]]++;
        // }

        // vector<int> cities(n);
        // for (int i = 0; i < n; ++i) {
        //     cities[i] = i;
        // }

        // sort(cities.begin(), cities.end(), [&degree](int a, int b) {
        //     return degree[a] > degree[b];
        // });

        // vector<int> values(n);
        // int currentValue = n;
        // for (int city : cities) {
        //     values[city] = currentValue--;
        // }

        // long long totalImportance = 0;
        // for (const auto& road : roads) {
        //     totalImportance += values[road[0]] + values[road[1]];
        // }

        // return totalImportance;

        // simple approach
        long long imp = 0;
        vector<long long> degree(n, 0);

        // making the degrees of node
        for (auto it : roads) {
            degree[it[0]]++;
            degree[it[1]]++;
        }
        // sort the degrees in ascending order
        sort(degree.begin(), degree.end());

        for (long long i = 0; i < n; i++) {

            // given the unique importance of city or node base on its connection and
            // simply multiply by connection
            imp += ((i + 1) * degree[i]);
        }

        return imp;
    }
};