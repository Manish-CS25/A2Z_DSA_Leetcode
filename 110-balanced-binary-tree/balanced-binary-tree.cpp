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
    int check(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int lt = check(node->left);
        int rt = check(node->right);

        if (lt == -1 || rt == -1)
            return -1;
        if (abs(lt - rt) > 1)
            return -1;
        return max(lt, rt) + 1;
    }

    bool isBalanced(TreeNode* root) { return check(root) != -1; }
};