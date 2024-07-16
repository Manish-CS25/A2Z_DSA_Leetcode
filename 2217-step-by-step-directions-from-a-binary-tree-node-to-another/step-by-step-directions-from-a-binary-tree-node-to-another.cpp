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
    TreeNode* lca(TreeNode* node, int s, int d) {
        if (node == nullptr) {
            return node;
        }
        TreeNode* leftside = lca(node->left, s, d);
        TreeNode* rightside = lca(node->right, s, d);

        if (leftside && rightside || (node->val == s || node->val == d)) {
            return node;
        }

        return (leftside == nullptr) ? rightside : leftside;
    }
    string lcaTostart, lcaToend;
    void dfs(TreeNode* Node, string& pathString, int s, int d) {
        if (!Node) {
            return;
        }
        if (Node->val == s)
            lcaTostart = pathString;
        if (Node->val == d)
            lcaToend = pathString;

        pathString.push_back('L');
        dfs(Node->left, pathString, s, d);
        pathString.pop_back();

        pathString.push_back('R');
        dfs(Node->right, pathString, s, d);
        pathString.pop_back();
    }

    string getDirections(TreeNode* root, int s, int d) {
        string pathString = "";
        TreeNode* lcaNode = lca(root, s, d);
        dfs(lcaNode, pathString, s, d);

        for (auto& ch : lcaTostart)
            ch = 'U';

        return lcaTostart + lcaToend;
    }
};