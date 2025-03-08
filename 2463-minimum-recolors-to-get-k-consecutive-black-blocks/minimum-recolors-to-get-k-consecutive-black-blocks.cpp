class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minOp = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                minOp++;
        }
        int tempMinOp = minOp;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W')
                tempMinOp--;
            if (blocks[i] == 'W')
                tempMinOp++;
            minOp = min(minOp, tempMinOp);
        }
        return minOp;
    }
};