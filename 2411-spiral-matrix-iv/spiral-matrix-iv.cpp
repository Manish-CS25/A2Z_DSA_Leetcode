/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int topRow = 0;
        int leftCol = 0;
        int bottomRow = m - 1;
        int rightCol = n - 1;

        while (head != NULL) {
            // ==================LEft to Right==============
            for (int col = leftCol; col <= rightCol; col++) {
                if (head == NULL)
                    break;
                matrix[topRow][col] = head->val;
                head = head->next;
            }
            topRow++;

            // ==================top to down==============

            for (int row = topRow; row <= bottomRow; row++) {
                if (head == NULL)
                    break;
                matrix[row][rightCol] = head->val;
                head = head->next;
            }

            rightCol--;

            // ==================right to left==============

            for (int col = rightCol; col >= leftCol; col--) {
                if (head == NULL)
                    break;
                matrix[bottomRow][col] = head->val;
                head = head->next;
            }
            bottomRow--;
            // ==================up to Down==============

            for (int row = bottomRow; row >= topRow; row--) {
                if (head == NULL)
                    break;
                matrix[row][leftCol] = head->val;
                head = head->next;
            }

            leftCol++;
        }
        return matrix;
    }
};