class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<vector<int>,int>m;
        set<int>s;
        int count =0;
        for(auto i:pick){
            m[i]++;
        }
        for(auto i:m){
            if(i.first[0] < i.second && !s.contains(i.first[0])){
                s.insert(i.first[0]);
                count++;
            }
        }
        return count;
    }
};