class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<int> new_no(n);

        // Convert each number to its mapped value
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int mapped_num = 0;
            int place = 1;

            if (num == 0) {
                mapped_num = mapping[0];
            } else {
                while (num > 0) {
                    int digit = num % 10;
                    mapped_num += mapping[digit] * place;
                    place *= 10;
                    num /= 10;
                }
            }
            new_no[i] = mapped_num;
        }

        // Pair the mapped values with the original numbers
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({new_no[i], nums[i]});
        }

        // Stable sort based on the mapped values
        stable_sort(p.begin(), p.end(),
                    [](const pair<int, int>& a, const pair<int, int>& b) {
                        return a.first < b.first;
                    });

        // Update the nums array with the sorted values
        for (int i = 0; i < n; i++) {
            nums[i] = p[i].second;
        }

        return nums;
    }
};
