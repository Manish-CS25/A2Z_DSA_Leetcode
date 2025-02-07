class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colBall;
        unordered_map<int , int> ballCol;
        vector<int> ans;
        for(auto i : queries)
        {
            int col = i[1]; int ball = i[0];
            // we will get a color and a ball , we will check if that ball already has a color or not,
            // if it doesnt have a color , we will increase count for a color thats it
            if(ballCol.find(ball)==ballCol.end())
                {colBall[col]++;}
            else // otherwise we would getthe previous color and decrease it
            {
                int prevcol = ballCol[ball];
                colBall[prevcol]--;
                if(colBall[prevcol]==0){
                    colBall.erase(prevcol);
                }
                colBall[col]++;
            }
            ballCol[ball]=col;
            ans.push_back(colBall.size());
        }
        return ans;
    }
};