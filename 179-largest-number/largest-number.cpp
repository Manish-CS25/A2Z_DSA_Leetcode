class Solution {
public:
    static bool comp(int a, int b) {
        string str_a = to_string(a);
        string str_b = to_string(b);
        return str_a + str_b > str_b + str_a;
    }
    string largestNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for (auto it : nums) {
            ans += to_string(it);
        }
        if (ans[0] == '0')
            return "0";

        return ans;
    }
};