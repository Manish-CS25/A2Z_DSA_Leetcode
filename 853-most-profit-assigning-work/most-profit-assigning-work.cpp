class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int ans = 0;
        for (int i = 0; i < worker.size(); i++) {
            int max_p= 0;
            for (int j = 0; j < difficulty.size(); j++){
                if(worker[i] >= difficulty[j])
                max_p = max(max_p , profit[j]);
            }
            ans += max_p;
        }
        return ans;
    }
};