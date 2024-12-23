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
    int countSwap(vector<int>& nodes) {
        unordered_map<int, int> mp;

        int swaps = 0;

        vector<int> sorted(nodes.begin(), nodes.end());

        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < nodes.size(); i++) {
            mp[nodes[i]] = i;
        }

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == sorted[i])
                continue;

            int curr_index = mp[sorted[i]];
            mp[nodes[i]] = curr_index;

            mp[nodes[curr_index]] = i;
            swap(nodes[i], nodes[curr_index]);

            swaps++;
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {

            int size = q.size();

            vector<int> nodes;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node->val);
                if (node->left) {

                    q.push(node->left);
                }

                if (node->right) {

                    q.push(node->right);
                }
            }

            cnt += countSwap(nodes);
        }

        return cnt;
    }
};