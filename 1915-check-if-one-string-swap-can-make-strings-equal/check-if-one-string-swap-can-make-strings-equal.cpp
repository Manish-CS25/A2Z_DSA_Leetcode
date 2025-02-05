class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        set<int> t1, t2;
        t1 = t2 = {};
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                t1.insert(s1[i]);
                t2.insert(s2[i]);
            }
        }

        if (cnt != 2 && cnt != 0) {

            return false;
        }

        else {
            if (t1 != t2) {

                return false;
            }
        }

        return true;
    }
};