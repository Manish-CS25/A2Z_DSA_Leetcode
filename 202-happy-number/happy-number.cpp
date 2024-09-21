class Solution {
public:
    bool isHappy(int n) {

        if (n == 1)
            return true;
        int sum =0;
        while (n > 1) {
            while (n > 0) {
                int m = n % 10;
                n = n / 10;
                sum += m * m;
            }

            if (sum == 1)
                return true;
            n=sum;
            sum=0;
            if (n == 4)
                return false;
        }

        return false;
    }
};