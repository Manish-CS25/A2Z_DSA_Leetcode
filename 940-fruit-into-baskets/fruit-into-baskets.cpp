

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int L = 0, R = 0, max_f = 0;

        while (R < fruits.size()) {
            mpp[fruits[R]]++; // Increment the frequency of the rightmost fruit

            // If the current window contains more than two types of fruits
            while (mpp.size() > 2) {
                mpp[fruits[L]]--; // Decrement the frequency of the leftmost
                                  // fruit

                // If the leftmost fruit's frequency becomes zero, remove it
                // from the map
                if (mpp[fruits[L]] == 0) {
                    mpp.erase(fruits[L]);
                }
                L++; // Move the left pointer to the right
            }

            if (mpp.size() <= 2) {

                max_f = max(R - L + 1, max_f);
            }

            R++; // Move the right pointer to the right
        }

        return max_f;
    }
};
