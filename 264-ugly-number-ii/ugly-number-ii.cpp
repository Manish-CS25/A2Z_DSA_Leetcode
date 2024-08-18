class Solution {
public:
    //     bool not_prime235(int k) {
    //         if (k <= 12)
    //             return true;
    //         vector<int> factor;
    //         for (int i = 5; i <= k / 2; i++) {
    //             if (k % i == 0) {
    //                 int flag = 0;
    //                 for (int j = 2; j <= i / 2; j++) {

    //                     if (i % j == 0) {
    //                         flag = 1;
    //                     }
    //                 }
    //                 if (!flag && i > 5) {
    //                     return false;
    //                 }
    //             }
    //         }
    //         return true;
    //     }

    int nthUglyNumber(int n) {

        vector<int> ans;
        ans.push_back(1);
        // int i = 2;
        // while (ans.size() < n) {
        //     if ((i % 2 == 0 || i % 3 == 0 || i % 5 == 0) && not_prime235(i))
        //     {

        //         ans.push_back(i);
        //         i++;
        //         continue;
        //     }

        //     i++;
        // }
        // for (auto it : ans)
        //     cout << it;

        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            int next_u_no = min(min(ans[i2] * 2, ans[i3] * 3), ans[i5] * 5);
            ans.push_back(next_u_no);

            if (next_u_no == ans[i2] * 2)
                i2++;
            if (next_u_no == ans[i3] * 3)
                i3++;
            if (next_u_no == ans[i5] * 5)
                i5++;
        }

        return ans[n - 1];
    }
};