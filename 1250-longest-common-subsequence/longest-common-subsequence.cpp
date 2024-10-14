// ================Brute force Solution ---TLE============

// class Solution {
// public:
//     int f(int i, int j, string& s1, string& s2) {
//         if (i < 0 || j < 0)
//             return 0;

//         if (s1[i] == s2[j])
//             return 1 + f(i - 1, j - 1, s1, s2);

//         return 0 + max(f(i - 1, j, s1, s2), f(i, j - 1, s1, s2));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size();
//         int n = text2.size();

//         return f(m - 1, n - 1, text1, text2);
//     }
// };

// ====================DP Solution---Recursive========================
//=====================Top Down Approach ============================

// class Solution {
// public:
//     int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
//         if (i < 0 || j < 0)
//             return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s1[i] == s2[j])
//             return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

//         return dp[i][j] =
//                    0 + max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size();
//         int n = text2.size();

//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return f(m - 1, n - 1, text1, text2, dp);
//     }
// };

// ====================DP---Bottom Approach===================
// Iterative Solution

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size();
//         int n = text2.size();

//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//         for (int i = 0; i <= m; i++)
//             dp[i][0] = 0;
//         for (int j = 0; j <= n; j++)
//             dp[0][j] = 0;

//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {

//                 if (text1[i - 1] == text2[j - 1])
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 else

//                     dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }

//         return dp[m][n];
//     }
// };

// ========Space Optimization =============

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int j = 0; j <= n; j++)
            prev[j] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else

                    curr[j] = 0 + max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[n];
    }
};