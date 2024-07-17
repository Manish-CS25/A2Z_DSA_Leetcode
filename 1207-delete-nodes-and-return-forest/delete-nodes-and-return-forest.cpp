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
    unordered_set<int> st;
    void deleteNode(TreeNode*& root, vector<TreeNode*>& ans) {
        if (!root) {
            return;
        }

        deleteNode(root->left, ans);
        deleteNode(root->right, ans);
        if (st.find(root->val) != st.end()) {
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);
            root = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;

        int n = to_delete.size();
        for (int i = 0; i < n; i++) {
            st.insert(to_delete[i]);
        }
        deleteNode(root, ans);

        if (root)
            ans.push_back(root);
        return ans;
    }
};