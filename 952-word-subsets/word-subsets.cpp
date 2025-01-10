class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int count[26]={0};
        for (int j = 0; j < words2.size(); j++) {
            int count2[26]={0};
            for (char it : words2[j]) {
                count2[it - 'a']++;
                count[it-'a'] = max(count2[it-'a'] , count[it-'a']);
            }
        
        }

        for(string &w1 : words1){
            int count2[26] = {0};
            for(char ch : w1){
                count2[ch-'a']++;
            }
            for(int i = 0; i<=26; i++){
                if(i==26){
                    ans.push_back(w1);
                    break;
                }
                if(count[i]>count2[i]) break;
            }
        }

        return ans;
    }
};