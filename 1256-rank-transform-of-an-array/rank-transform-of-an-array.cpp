class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return arr;
        
        // Step 1: Create a sorted copy of the array and remove duplicates
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end()); // Remove duplicates
        
        // Step 2: Create a map that associates each unique element with its rank
        unordered_map<int, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i + 1;  // Rank starts from 1
        }

        // Step 3: Replace each element in the original array with its rank
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};
