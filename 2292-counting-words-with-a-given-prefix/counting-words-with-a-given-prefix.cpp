class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt= 0;
        for(int i=0;i<words.size();i++){
            int index = words[i].find(pref);

            if(index != string::npos){
                if(index==0) cnt++;
            }
        }
        return cnt;
    }
};