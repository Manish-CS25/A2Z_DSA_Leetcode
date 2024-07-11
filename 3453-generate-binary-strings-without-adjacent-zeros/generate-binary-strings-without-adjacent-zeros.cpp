class Solution {
public:
 void helper(vector<string> &ans , int index , int n , string s){
    if(index==n){
        ans.push_back(s);
        return;
    }
    if(s[index-1]=='0'){
        helper(ans , index+1 , n , s+"1");

    }
    else{
        helper(ans , index+1 , n , s+"0");
        helper(ans , index+1 , n , s+"1");
    }
 }
   
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(ans , 1 , n , "0");
        helper(ans , 1 , n , "1");

        return ans;

    }
};