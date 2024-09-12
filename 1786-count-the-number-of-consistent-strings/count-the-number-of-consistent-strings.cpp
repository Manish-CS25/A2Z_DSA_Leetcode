class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        int cnt = 0;
        for (auto it : allowed) {
            mp[it]++;
        }

        for (int i = 0; i < words.size(); i++) {
            int flag = 1;
            for (auto it : words[i]) {
                if (mp[it] == 0)
                    flag = 0;
            }
            if (flag)
                cnt++;
        }
        return cnt;
    }
};