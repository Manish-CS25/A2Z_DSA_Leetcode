class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        // int l=0;
        // int r=1;
        long long cnt = 0;
        int n = hours.size();

        map<int, int> mpp;

        for (int i = 0; i < n; i++) {

            // finding the reminder of 24 for each element
            long long rem = hours[i] % 24;
            // finding the comparative part to make it 0 when mod 24
            long long comp = (24 - rem) % 24;

            // if comp is already in map then we find one pair of complete day
            if(mpp.find(comp)!=mpp.end())
            // we update our no. of complete day count by frequency of comp in map
            cnt+=mpp[comp];

            // else we will increase frquency of rem in map
            mpp[rem]++;

        }

        return cnt;
    }
};