
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);

        // In  first pass just store prefix product in ans[i] (left->right)
        int curr = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= curr;
            curr *= nums[i];
        }

        // In  second pass just store  suffix product that would multilpy with
        // already existed prefix product (right->left)
        curr = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= curr;
            curr *= nums[i];
        }

        return ans;
    }
};