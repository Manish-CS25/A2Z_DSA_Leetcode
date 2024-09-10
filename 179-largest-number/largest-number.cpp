class Solution {
public:
    // Custom comparator to decide the order of concatenation
    static bool comp(int a, int b) {
        string str_a = to_string(a);
        string str_b = to_string(b);
        return str_a + str_b > str_b + str_a;
    }

    string largestNumber(vector<int>& nums) {
        // Sort numbers using the custom comparator
        sort(nums.begin(), nums.end(), comp);

        // Create the largest number by concatenating sorted numbers
        string ans = "";
        for (auto it : nums) {
            ans += to_string(it);
        }

        // Handle edge case where all numbers are zero
        if (ans[0] == '0')
            return "0";

        return ans;
    }
};
