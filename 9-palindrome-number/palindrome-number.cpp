class Solution {
public:
    bool isPalindrome(int x) {
        int value = x;
        long rnumber = 0;
        while (x > 0) {
            int k = x % 10;
            x = x / 10;
            rnumber = rnumber * 10 + k;
        }
        if (value == rnumber)
            return true;
        return false;
    }
};