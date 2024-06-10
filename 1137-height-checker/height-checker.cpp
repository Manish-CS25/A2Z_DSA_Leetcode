class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> arr(heights);


        sort(arr.begin(), arr.end());

        for (int i = 0; i < heights.size(); i++) {
            if (arr[i] != heights[i])
                count++;
        }
        return count;
    }
};