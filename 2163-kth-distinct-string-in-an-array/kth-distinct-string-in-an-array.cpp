class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        // Count frequency of each string
        for (const string& s : arr) {
            mp[s]++;
        }

        // Find the k-th distinct string
        for (const string& s : arr) {
            if (mp[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                }
            }
        }

        return "";
    }
};