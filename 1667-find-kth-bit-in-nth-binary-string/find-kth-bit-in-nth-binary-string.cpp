class Solution {
public:
    char helper(long long len, int k) {

        if (len == 1)
            return '0';

        // char ans = '0';
        int half = len / 2;

        int middle = half + 1;

        if (k == middle) {
            return '1';
        } else if (k < middle) {
            return helper(half, k);
        }

        else {

            char ans = helper(half, 1 + len - k);
            return ans == '0' ? '1' : '0';
        }
    }

    char findKthBit(int n, int k) {

        long long len = (1<<n) - 1;

        return helper(len, k);
    }
};