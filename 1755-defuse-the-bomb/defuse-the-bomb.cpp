class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> sum_arr(n, 0);
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                code[i] = 0;
            }
        }

        if (k < 0) {
            k *= -1;
            for (int i = 0; i < n; i++) {
                int j = 0;
                int index = 0;
                while (j < k) {
                    if ((i - j - 1) < 0)
                        index = (i - j - 1 + n) % n;
                    else
                        index = (i - j - 1) % n;
                    sum_arr[i] += code[index];
                    j++;
                }
            }
        }

        else if (k > 0) {
            for (int i = 0; i < n; i++) {
                int j = 0;
                while (j < k) {
                    int index = (i + j + 1) % n;
                    sum_arr[i] += code[index];
                    j++;
                }
            }
        }
        return sum_arr;
    }
};