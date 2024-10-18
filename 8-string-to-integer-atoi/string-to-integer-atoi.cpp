

class Solution {
public:
    int myAtoi(std::string s) {
        int n = s.size();
        int i = 0;
        bool sign = true;
        long long ans = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check if we have reached the end after removing spaces
        if (i == n) return 0;

        // Check for the sign
        if (s[i] == '-') {
            sign = false;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // Convert the digits to integer
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow and underflow
            if (ans > INT_MAX) {
                return sign ? INT_MAX : INT_MIN;
            }
            i++;
        }

        // Apply the sign
        ans = sign ? ans : -ans;

        // Return the result as an int
        return (int)ans;
    }
};
