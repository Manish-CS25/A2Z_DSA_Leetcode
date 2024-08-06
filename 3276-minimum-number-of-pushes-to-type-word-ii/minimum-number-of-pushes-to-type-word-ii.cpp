
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (char c : word) {
            mp[c]++;
        }

        vector<int> frequencies;
        for (auto it : mp) {
            frequencies.push_back(it.second);
        }

        sort(frequencies.rbegin(), frequencies.rend());

        int cnt = 0;
        int multiplier = 1;

        for (int i = 0; i < frequencies.size(); i++) {
            if (i > 0 && i % 8 == 0) {
                multiplier++;
            }
            cnt += multiplier * frequencies[i];
        }

        return cnt;
    }
};