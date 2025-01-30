class Solution {
public:
    int mySqrt(int x) {
        int n = x / 2;
        int ans = 0;
        if(x==1 ) return x;

        for (long long i = 1; i <= n; i++) {
            if (i * i <= x) {
                ans = i;
            }

            else
                break;
        }
        return ans;
    }
};