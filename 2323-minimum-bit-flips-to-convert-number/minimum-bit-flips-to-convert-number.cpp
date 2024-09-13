class Solution {
public:
    int minBitFlips(int start, int goal) {
        int  a = start ^ goal;
        long long cnt = 0;
        while (a>0) {
            if (a % 2 == 1) 
                cnt++;
            

            a /= 2;
        }
        return cnt;
    }
};