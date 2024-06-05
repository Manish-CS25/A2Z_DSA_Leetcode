class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int maxf = 0; // maximum frequency of a single character in the current window
        int count[26] = {0}; // frequency count of each character in the window
        
        for (int i = 0, j = 0; j < s.size(); ++j) {
            maxf = max(maxf, ++count[s[j] - 'A']);
            
            // Current window size is (j - i + 1)
            // Number of characters we need to change is (window size - maxf)
            if (j - i + 1 - maxf > k) {
                // If the number of changes needed is greater than k, we shrink the window from the left
                --count[s[i] - 'A'];
                ++i;
            }
            
            // Update the maximum length of the valid window
            maxlen = max(maxlen, j - i + 1);
        }
        
        return maxlen;
    }
};
