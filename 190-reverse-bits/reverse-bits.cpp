class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans =0;
        stack<int> q;
        while(n){
            q.push(n%2);
            n/=2;
        }
        int i=0;
        while(q.size()<32){
            q.push(0);
        }
        while(!q.empty()){
            ans+=pow(2, i)*q.top();
            q.pop();
            i++;
        }

        return ans;
        
    }
};