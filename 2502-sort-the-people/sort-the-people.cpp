class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> p;
        int i = 0;
        while (i < n) {
            p.push_back({heights[i], names[i]});
            i++;
        }

        sort(p.begin(), p.end());
        for (int i = n - 1; i >= 0; i--) {
            cout<<p[i].first;
            names[n-i-1] = p[i].second;
        }

        return names;
    }
};