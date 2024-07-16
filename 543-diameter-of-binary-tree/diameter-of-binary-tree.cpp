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
// class Solution {
// public:
//     int height(TreeNode* root) {
//         if (root == NULL) {
//             return 0;
//         }

//         int left = height(root->left);
//         int right = height(root->right);

//         int ans = max(left, right) + 1;
//         return ans;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {

//         if (root == NULL) {
//             return 0;
//         }
//         int left_d = diameterOfBinaryTree(root->left);
//         int right_d = diameterOfBinaryTree(root->right);
//         int ans = height(root->left) + height(root->right);
//         int d = max(left_d, max(right_d, ans));

//         return d;
//     }
// };

// ===============Optimal Solution ===========================
class Solution {
public:
    int height(TreeNode* Node, int& d) {
        if (Node == NULL) {
            return 0;
        }

        int LH = height(Node->left, d);
        int RH = height(Node->right, d);
        d = max(d, LH + RH);
        return 1 + max(LH, RH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(root, d);
        return d;
    }
};
