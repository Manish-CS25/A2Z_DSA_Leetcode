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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Priority queue to store level sums
        priority_queue<long long> pq;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 1});
        int curr_level = 1;
        long long sum = 0;

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            // If we're still processing the same level, add to sum
            if (level == curr_level) {
                sum += node->val;
            } else {
                // Push the sum of the previous level to the priority queue
                pq.push(sum);
                // Reset the sum for the new level
                sum = node->val;
                curr_level = level;
            }

            // Enqueue child nodes with their corresponding levels
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }

        // Don't forget to push the sum for the last level
        pq.push(sum);

        if (pq.size() < k) {
            return -1;
        }

        // Pop the top (largest) sums k-1 times to get the k-th largest sum
        for (int i = 1; i < k; i++) {
            if (!pq.empty()) {
                pq.pop();
            } else {
                // If k is larger than the number of levels, return -1 or handle
                // it
                return -1;
            }
        }

        // Return the k-th largest sum
        return pq.top();
    }
};
