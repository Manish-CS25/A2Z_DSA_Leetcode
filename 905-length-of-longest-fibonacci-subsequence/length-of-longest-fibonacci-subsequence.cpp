class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxLen = 0;
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) index[arr[i]] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j], len = 2;
                while (index.count(a + b)) {
                    tie(a, b) = make_pair(b, a + b);
                    len++;
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen > 2 ? maxLen : 0;
    }
};