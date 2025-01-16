class Solution {
public:
    int SetBits(int num) {
        int cnt = 0;
        while (num) {
            int bit = num % 2;
            if (bit == 1)
                cnt++;
            num /= 2;
        }

        return cnt;
    }
    int minimizeXor(int num1, int num2) {

        int ans = 0;

        int targetSetBits = SetBits(num2);

        for (int i = 31; i >= 0 && targetSetBits > 0; i--) {
            if (num1 & (1 << i)) {
                ans |= (1 << i);
                targetSetBits--;
            }
        }

        for (int i = 0; i < 32 && targetSetBits > 0; i++) {
            if (!(ans & (1 << i))) {
                ans |= (1 << i);
                targetSetBits--;
            }
        }

        return ans;
    }
};