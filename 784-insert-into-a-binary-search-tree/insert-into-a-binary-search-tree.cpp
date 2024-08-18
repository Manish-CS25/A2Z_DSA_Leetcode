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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if (root == NULL) {
            return newnode;
        }
        TreeNode* temp = root;

        while (temp) {
            if (temp->left == NULL && val < temp->val) {
                temp->left = newnode;
                break;
            }

            if (temp->right == NULL && val > temp->val) {
                temp->right = newnode;
                break;
            }

            if (val > temp->val) {
                temp = temp->right;

            } else
                temp = temp->left;
        }
        return root;
    }
};