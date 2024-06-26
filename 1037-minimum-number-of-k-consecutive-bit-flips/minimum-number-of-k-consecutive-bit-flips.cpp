class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        // Bruteforce approach

        // int cnt = 0;
        // for (int i = 0; i < nums.size() - k +1; i++) {
        //     if (nums[i] == 0) {
        //         cnt++;
        //         int j = 0;
        //         while (j < k) {
        //             if (nums[i + j] == 0)
        //                 nums[i + j] = 1;
        //             else
        //                 nums[i + j] = 0;
        //             j++;
        //         }

        //     }
        // }

        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == 0)
        //         return -1;
        // }
        // return cnt;

        // optimal approach---coder army

        // queue<int> q;
        // int flip = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (!q.empty() && q.front() < i) {
        //         q.pop();
        //     }
        //     if (q.size() % 2 == nums[i]) {
        //         if (i + k - 1 >= nums.size())
        //             return -1;

        //         q.push(i + k - 1);
        //         flip++;
        //     }
        // }

        // return flip;

        // most optimal approach

        int n = nums.size(), res = 0, flipped = 0;
        vector<int> isflipped(n, 0);

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipped ^= isflipped[i - k];
            }
            if (flipped == nums[i]) {
                if (i + k > n)
                    return -1;

                isflipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }

        return res;
    }
};