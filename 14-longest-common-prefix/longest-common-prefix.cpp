class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string p = "";
        int n = INT_MAX;
        for(int i=0; i<strs.size();i++){
            if(n>strs[i].size())
            n = strs[i].size();

        }
        for (int i = 0; i <n; i++) {


            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i])
                    return p;
            }
            p += strs[0][i];
        }
        return p;
    }
};