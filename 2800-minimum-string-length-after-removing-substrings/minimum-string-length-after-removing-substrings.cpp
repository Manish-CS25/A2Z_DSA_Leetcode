class Solution {
public:
    int minLength(string s) {

        int j = 0;
        while (j < s.size() - 1)

        {

            if (s.size() < 2) {
                break; // Exit if fewer than 2 characters remain
            }
            string st = s.substr(j, 2);
            if (st == "AB" || st == "CD") {
                s.erase(j, 2);
                if (j > 0)
                    j--;
            }

            else
                j++;
        }

        return s.size();
    }
};