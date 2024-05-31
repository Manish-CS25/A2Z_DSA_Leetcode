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
//     void postorder(TreeNode* node , vector<int>& p)
//     {   if(node==NULL) return;
//         postorder(node->left, p);
//         postorder(node->right, p);
//         p.push_back(node->val);

//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> p;
//         postorder(root, p);
//         return p;
//     }
// };

// Iterative solution using 2 Stacks

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> p;
        if (root == NULL)
            return p;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {

            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left != NULL)
                st1.push(root->left);
            if (root->right != NULL)
                st1.push(root->right);
        }

        while (!st2.empty()) {
            p.push_back(st2.top()->val);
            st2.pop();
        }
        return p;
    }
};