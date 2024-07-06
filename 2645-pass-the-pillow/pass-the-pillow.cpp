class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = 1;
        int flag = 1;
        while (time) {
            time -= 1;
            if (flag) {
                pos += 1;
                if (pos == n)
                    flag = 0;
            } else {
                pos -= 1;
                if (pos == 1) {
                    flag = 1;
                }
            }
        }
        return pos;
    }
};