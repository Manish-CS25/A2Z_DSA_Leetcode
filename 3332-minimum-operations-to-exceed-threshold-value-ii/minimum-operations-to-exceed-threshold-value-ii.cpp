class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long , vector<long long> , greater<long long>> minheap;
        for(auto it:nums) minheap.push(it);
        int i=0;
        while(minheap.size()>=2){
            long long s1 = minheap.top();
            minheap.pop();
            long long s2 = minheap.top();
            minheap.pop();

            if(s1>=k && s2>=k) break;

            long long s3 = min(s1, s2)*2 + max(s1 , s2);
            minheap.push(s3);
            i++;

        }
        return i;
    }
};