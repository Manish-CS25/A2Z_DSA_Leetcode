class Solution {
    long long mod = 1e9 + 7;

public:
    long long power(long long x, long long n) {
        if (n == 0)
            return 1;

        if (n % 2 == 0) {
            return power((x * x) % mod, n / 2);
        } else {
            return (x * power(x, n - 1)) % mod;
        }
    }

public:
    int countGoodNumbers(long long n) {

        // long long mod = 1000000007;
        // long long n1 = long(pow(5, floor((n + 1) / 2))) % mod;

        // long long n2 = long(pow(4, floor(n / 2))) % mod;
        // long long result = (n1 * n2) % mod;
        // return result; // n1 * n2;

        // another Appraoch
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long f_half = power(5, even);
        long long s_half = power(4, odd);

        return (f_half * s_half) % mod;
    }
};