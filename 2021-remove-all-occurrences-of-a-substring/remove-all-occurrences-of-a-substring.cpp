class Solution {
public:
    string removeOccurrences(string s, string part) {

        while (s.find(part) != string::npos) {

            int i = s.find(part);
            s = (s.substr(0, i) + s.substr(i + part.size()));
        }

        return s;
    }
};