// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {

//         // int max_b=2;
//         map<int, int> mpp;

//         int L, R, max_f;
//         L = R = max_f = 0;
//         while (R < fruits.size()) {

//             mpp[fruits[R]]++;
//             if (mpp.size() > 2) {
//                 mpp[fruits[L]]--;
//                 if (mpp[fruits[L]] == 0) {
//                     mpp.erase(mpp[fruits[L]]);
//                 }
//                 L++;
//             }

//             if (mpp.size() <= 2) {

//                 max_f = max(R - L + 1, max_f);
//             }

//             R++;
//         }
//         return max_f;

//     }
// };

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int L = 0, R = 0, max_f = 0, count = 0;

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

            // Update the maximum number of fruits collected
            // count = 0;
            // for (auto it : mpp) {
            //     count += it.second;
            // }
            // max_f = max(max_f, count);

            if (mpp.size() <= 2) {

                max_f = max(R - L + 1, max_f);
            }

            R++; // Move the right pointer to the right
        }

        return max_f;
    }
};
