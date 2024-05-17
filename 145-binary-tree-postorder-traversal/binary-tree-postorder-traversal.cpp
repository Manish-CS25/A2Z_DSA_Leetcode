/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorder(TreeNode* node , vector<int>& p)
    {   if(node==NULL) return;
        postorder(node->left, p);
        postorder(node->right, p);
        p.push_back(node->val);
        

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> p;
        postorder(root, p);
        return p;
    }
};