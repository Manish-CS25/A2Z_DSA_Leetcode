class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: Store unique elements in a set
        set<int> uniqueElements(arr.begin(), arr.end());

        // Step 2: Sort the unique elements to determine their ranks
        vector<int> sortedUnique(uniqueElements.begin(), uniqueElements.end());

        // Step 3: Create a mapping from element to its rank
        unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedUnique.size(); i++) {
            rankMap[sortedUnique[i]] = i + 1; // rank starts from 1
        }

        // Step 4: Transform the original array using the rank map
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }

        return arr;
    }
};