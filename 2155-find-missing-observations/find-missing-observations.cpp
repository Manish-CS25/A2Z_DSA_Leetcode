class Solution {
    public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
     
        long long sum = 0;
        long long m = rolls.size();
        for (auto it : rolls) {
            sum += it;
        }

        long long rem = ((n + m) * mean) - sum;
        if((rem > (n*6))|| rem<n)
        return {};
        long long first = rem/n;
        rem = rem%n;
        vector<int> ans(n, first);
        int i=0;
        while(i<n && rem>0){
            if(ans[i]+rem <=6){
                ans[i]+=rem;
                rem =0;
            }
            else{
                int temp = 6-ans[i];
                ans[i]=6;
                rem -= temp;
            }
            i++;
        }
        return ans;

    }
};