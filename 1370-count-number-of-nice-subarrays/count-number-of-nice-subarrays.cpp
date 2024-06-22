class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
       int n = v.size();
       unordered_map<int , int> m;
       for(int i=0;i<n;i++){
        if(v[i]&1){
            v[i]=1;
        }
        else 
          v[i]=0;
       }

       int sum =0 , i , cnt=0;
       for(i=0; i<n;i++){
        sum += v[i];
        if(sum==k){
            cnt++;
        }
        int rem = sum -k;
        if(m.find(rem)!=m.end()){
            cnt+=m[rem];

        }
        m[sum]++;

       }
       return cnt;

       
    }
};