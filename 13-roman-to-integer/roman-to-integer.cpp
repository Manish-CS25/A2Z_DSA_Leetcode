class Solution {
public:
    int romanToInt(string s) {
        int v = 0;
        int prev = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'I') {
                if (prev >= 5)
                    v--;
                else
                    v += 1;
            }

            if (s[i] == 'V') {
                prev = 5;

                v += 5;
            }

            if (s[i] == 'X') {
                // cout << prev;
                if (prev >= 50) {
                    v -= 10;

                }

                else

                    v += 10;
                prev = 10;
            }

            if (s[i] == 'L') {
                if (prev >= 500)
                    v -= 50;
                else
                    v += 50;
                prev = 50;
            }

            if (s[i] == 'C') {
                if (prev >= 500)
                    v -= 100;
                else
                    v += 100;
                prev = 100;
            }
            if (s[i] == 'D') {

                v += 500;
                prev = 500;
            }

            if (s[i] == 'M') {
                v += 1000;
                prev = 1000;
            }
        }
        return v;
    }
};