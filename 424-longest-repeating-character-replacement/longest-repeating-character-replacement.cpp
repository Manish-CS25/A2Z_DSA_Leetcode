class Solution {
public:
    int characterReplacement(string s, int k) {
        int L , R , maxf , maxlen ;
        L = R = maxf = maxlen =0;
        int hash[26]={0};

        while(R<s.size()){

            hash[s[R]-'A']++;
            maxf = max(maxf , hash[s[R]-'A'] );

            if(R-L+1-maxf>k){
                hash[s[L]-'A']--;
                L++;
            }

            maxlen = max(maxlen , R-L+1);
            R++;

        }
        return maxlen;
    }
};