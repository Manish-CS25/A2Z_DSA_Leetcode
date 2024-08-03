class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {

            mp[arr[i]]++;
        }

        for (int j = 0; j < n; j++) {
            if(mp.find(target[j]) == mp.end())
                return false;
            mp[target[j]]--;
        }

        for (int i = 0; i < n; i++) {

            if (mp[arr[i]] != 0)
                return false;
        }

        return true;
    }
};