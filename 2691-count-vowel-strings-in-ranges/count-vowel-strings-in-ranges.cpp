class Solution {
public:
    unordered_set<char> v = {'a' , 'e' , 'i' , 'o' ,'u'};
    bool check(string s){
        if(s.size()==0) return false;
        bool first = false , second = false;
        if((v.find(s[0])!=v.end()) && (v.find(s[s.size()-1])!=v.end()) )
        return true;
        return false;
       

    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = words.size();
        int prev = 0;
        vector<int> ps(n, 0);
        for(int i=0;i<words.size();i++){
           if(check(words[i])){
            ps[i] = prev + 1;
            prev = ps[i];
              
           } 
           else ps[i] = prev;
        }


        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int nos=0;
            if(queries[i][0]>0)
            nos = ps[queries[i][1]]-ps[queries[i][0]-1];
            else  nos =  ps[queries[i][1]];
            ans.push_back(nos);
        }

        return ans;


    }
};