class Solution {
public:
    int minOperations(vector<string>& logs) {
        int minOp = 0;
        int n = logs.size();
        for (int i = 0; i < n; i++) {
            if (logs[i] != "../" && logs[i] != "./")
                minOp++;
            if (logs[i] == "../" && minOp != 0)
                minOp--;
        }
        return minOp;
    }
};