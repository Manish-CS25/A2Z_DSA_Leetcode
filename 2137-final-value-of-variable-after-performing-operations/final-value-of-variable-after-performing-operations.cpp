class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (int i = 0; i < operations.size(); i++) {
            // string s = operations[i];
            // switch(i) {
            // case "--X":
            //     X--;
            //     break;
            // case "X--":
            //     X--;
            //     break;
            // case "++X":
            //     X++;
            //     break;
            // case "X++":
            //     X++;
            //     break;
            // }

            if(operations[i]=="--X")
            --X;
            if(operations[i]=="++X")
            ++X;
            if(operations[i]=="X++")
            X++;
            if(operations[i]=="X--")
            X--;                        
        }
        return X;
    }
};