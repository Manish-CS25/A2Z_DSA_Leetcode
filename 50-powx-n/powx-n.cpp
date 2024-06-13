class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n < 1) {
            n = abs(n);
            x = 1 / x;
        }

        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } else {
            return x * myPow(x, n - 1);
        }

        //// 2nd Approach
        // double ans = 1.0;
        // long long nn = n;

        // if (nn < 0)
        //     nn = -1 * nn;
        // while (nn) {
        //     if (nn % 2) {
        //         ans = ans * x;
        //         nn = nn - 1;
        //     } else {
        //         x = x * x;
        //         nn = nn / 2;
        //     }
        // }
        // if (n < 0)
        //     ans = (double)(1.0) / (double)(ans);
        // return ans;
    }
};