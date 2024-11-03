// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.length()!=goal.length()) return false;

//         if((s+s).find(goal)!=string::npos) //finding if goal is a substring
//         in s+s using string stl function return true;

//         return false;

//     }
// };

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        int len = s.size();

        for (int i = 0; i < len; i++) {
            s += s[i];
            string sub = s.substr(i + 1, len + 1);
            if (sub == goal)
                return true;
        }
        return false;
    }
};
