class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = INT_MIN;
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(arr[i], maxi);
            if (maxi < i + 1) {
                count++;
            }
        }

        return count;
    }
};