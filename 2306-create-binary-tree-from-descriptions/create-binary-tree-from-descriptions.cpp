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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        // Create nodes and construct the tree
        for (const auto& rel : d) {
            int parent = rel[0];
            int child = rel[1];
            bool isLeft = rel[2] == 1;
            
            // Create parent node if it doesn't exist
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            
            // Create child node if it doesn't exist
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }
            
            // Link the parent and child
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            
            // Mark this node as a child
            children.insert(child);
        }
        
        // The root node will be the one that is not a child of any other node
        TreeNode* root = nullptr;
        for (const auto& node : nodes) {
            if (children.find(node.first) == children.end()) {
                root = node.second;
                break;
            }
        }
        
        return root;
    }
};