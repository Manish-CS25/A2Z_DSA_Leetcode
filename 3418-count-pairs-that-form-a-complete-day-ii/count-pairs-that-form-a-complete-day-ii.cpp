class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        // int l=0;
        // int r=1;
        long long cnt = 0;
        int n = hours.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            long long rem = hours[i] % 24;
            long long comp = (24 - rem) % 24;
            if(mpp.find(comp)!=mpp.end())
            cnt+=mpp[comp];
            mpp[rem]++;

        }

        return cnt;
    }
};