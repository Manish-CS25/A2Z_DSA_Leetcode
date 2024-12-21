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
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;
        int level = 0;

        q.push(root);
        while (!q.empty()) {

            int size = q.size();

            vector<TreeNode*> nodes;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);

                if (level % 2 != 0) {
                    nodes.push_back(node);
                }
            }

            if (level % 2 != 0) {
                int l = 0;
                int r = nodes.size() - 1;
                while (l < r) {
                    swap(nodes[l]->val, nodes[r]->val);
                    l++;
                    r--;
                }
            }

            level++;
        }
        return root;
    }
};