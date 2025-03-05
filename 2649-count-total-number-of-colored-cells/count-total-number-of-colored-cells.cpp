class Solution {
public:
    long long coloredCells(int n) {
        // if (n == 1)
        //     return 1;
        // if (n == 2)
        //     return 5;

        // return coloredCells(n - 1) + 4 + 4*(n - 2);

        return pow(n - 1, 2) + pow(n, 2);
    }
};