class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;

        for (auto it : s) {
            int v = it - 'a' + 1;
            while (v) {
                sum += v % 10;
                v /= 10;
            }
            
        }

        // for (auto it : ans) {
        //     // cout << it;
        //     while (it > 9) {
        //         sum += it % 10;
        //         it /= 10;
        //     }

        //     sum += it;
        // }

        // cout << sum;
        // int new_sum =0;
        for (int i = 1; i < k; i++) {
            int t = 0;

            while (sum) {
                t += sum % 10;
                sum /= 10;
            }

            sum = t;
        }

        return sum;
    }
};