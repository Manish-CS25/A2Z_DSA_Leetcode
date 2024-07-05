class Solution {
public:
    bool checkValidString(string s) {
        int min, max;
        min = max = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                min = min + 1;
                max = max + 1;
            } else if (s[i] == ')') {
                min = min - 1;
                max = max - 1;
            } else {
                // when * comes , we can do either +1 , -1 or nothing
                min = min - 1;
                max = max + 1;
            }
            if (min < 0)
                min = 0;
            if (max < 0)
                return false;
        }
        return (min == 0);
    }
};