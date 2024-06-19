class Solution {
    public:
    bool possible(vector<int>& bloomDay, int days, int m, int k) {
        int count = 0;
        int no_b = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                count++;

            } else {
                no_b += count / k;
                count = 0;
            }
        }
        no_b += count / k;

        return no_b >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        
        if (n < val) {
            return -1;
        }
        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());




        // for (int i = min; i <= max; i++) {
        //     if (possible(bloomDay, i, m, k)) {
        //         return i;
        //     }
        // }


        // ==========commented code is linear search and gives TLE========


        // here is the binary approach

        int low = min, high = max;
        while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
        }
        return low;


        
    }


};