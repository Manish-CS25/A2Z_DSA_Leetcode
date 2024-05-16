class Solution {
public:
    double myPow(double x, int n) {
        // if (n == 0)
        //     return 1.0;
        // if (n == 1)
        //     return x;
        // double pro = x;
        // if (n > 0) {
        //     pro = pro * myPow(x, n - 1);
        // }
        // if (n < 0) {
        //     pro = pro * myPow(x, n + 1);
        // }
        // if(n < 0)
        // return 1 / pro;
        // else return  pro;

        //// 2nd Approach
        double ans = 1.0;
        long long nn = n;

        if (nn < 0)
            nn = -1 * nn;
        while (nn) {
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};