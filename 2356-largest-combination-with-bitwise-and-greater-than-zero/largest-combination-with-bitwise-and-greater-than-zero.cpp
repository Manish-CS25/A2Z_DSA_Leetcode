class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int longest = 0;



        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (auto candidate : candidates) {

                // check i-th  bit set bits count for every candidate
                if (candidate & (1 << i))
                    cnt++;
            }
            longest = max(longest, cnt);
        }

        return longest;
    }
};