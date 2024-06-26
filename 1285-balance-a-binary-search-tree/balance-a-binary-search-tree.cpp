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
    // inorder traverse tree to make sorted array of nodes
    void inOrderTrav(TreeNode* root, vector<int>& sorted_nodes) {

        if (root == NULL) {
            return;
        }

        inOrderTrav(root->left, sorted_nodes);
        sorted_nodes.push_back(root->val);
        inOrderTrav(root->right, sorted_nodes);
    }

    // Now we will build BST using these nodes
    TreeNode* buildBST(vector<int>& sorted_nodes, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(sorted_nodes[mid]);
        root->left = buildBST(sorted_nodes, left, mid - 1);
        root->right = buildBST(sorted_nodes, mid + 1, right);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> sorted_nodes;
        inOrderTrav(root, sorted_nodes);
        // Finally return the balanced BST
        return buildBST(sorted_nodes, 0, sorted_nodes.size() - 1);
    }
};