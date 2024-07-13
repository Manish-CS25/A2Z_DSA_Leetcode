/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxSum(TreeNode* root, int& max_sum) {

        if (root == NULL) {
            return 0;
        }

        int l = max(0, maxSum(root->left, max_sum));
        int r = max(0, maxSum(root->right, max_sum));
        max_sum = max(max_sum, l + r + root->val);
        return max(l, r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxSum(root, max_sum);

            return max_sum;
    }
};