class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        // for(int i=0;i<heights.size();i++){
        //     if(i==0){
        //         if(heights[i] > heights[i+1])
        //         count++;
        //     }
        //     else if(i==heights.size()-1)
        //     {
        //         if(heights[i]<heights[i-1])
        //         count++;
        //     }
        //     else{
        //         if(heights[i]>heights[i+1] || heights[i]<heights[i-1] )
        //         count++;
        //     }
        // }

        vector<int> arr(heights);


        sort(arr.begin(), arr.end());

        for (int i = 0; i < heights.size(); i++) {
            if (arr[i] != heights[i])
                count++;
        }
        return count;
    }
};