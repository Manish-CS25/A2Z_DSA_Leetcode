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
private:
int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}


public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        vector<int> gcd;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        if (n == 1)
            return head;
        for (int i = 0; i < n - 1; i++) {

            int g = GCD(arr[i], arr[i + 1]);
            gcd.push_back(g);
        }

        temp = head->next;
        ListNode* prev = head;
        int i = 0;
        while (temp) {
            ListNode* node = new ListNode(gcd[i]);
            prev->next = node;
            node->next = temp;
            prev = temp;
            temp = temp->next;
            i++;
        }
        return head;
    }
};