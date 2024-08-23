#include <bits/stdc++.h>
class Solution {
public:
    string fractionAddition(string s) {
        int num = 0, den = 1;

        int n = s.size();
        int i = 0;

        while (i < n) {

            int curr_num = 0, curr_den = 0;

            bool isNegative = false;

            if (s[i] == '-') {
                isNegative = true;
                i++;
            } else if (s[i] == '+') {
                i++;
            }

            while (i < n and (s[i] >= '0' and s[i] <= '9')) {
                curr_num = (curr_num * 10) + (s[i] - '0');
                i++;
            }

            if (isNegative) {
                curr_num *= -1;
            }

            if (s[i] == '/') {
                i++;
            }

            while (i < n and (s[i] >= '0' and s[i] <= '9')) {
                curr_den = (curr_den * 10) + (s[i] - '0');
                i++;
            }

            num = (num * curr_den) + (den * curr_num);
            den = (den * curr_den);
        }

        int gcd_val = __gcd(abs(num), den);

        num /= gcd_val;
        den /= gcd_val;

        string ans = to_string(num) + "/" + to_string(den);

        return ans;
    }
};