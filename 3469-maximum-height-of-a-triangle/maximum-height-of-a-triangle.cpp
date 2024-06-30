class Solution {
public:
    int maximizer(int ball1, int ball2) {
        int h = 0;
        for (int i = 1; ; i++) {
            ball1 -= 2 * i - 1;
            if (ball1 >= 0)
                h++;
            else
                break;

            ball2 -= 2 * i; if (ball2 >= 0) h++;
            else break;
        }
        return h;
    }
    int maxHeightOfTriangle(int red, int blue) {

        return max(maximizer(red, blue), maximizer(blue, red));
    }
};