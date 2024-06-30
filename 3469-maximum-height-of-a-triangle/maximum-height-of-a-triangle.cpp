class Solution {
public:
    int maximizer(int ball1, int ball2) {
        int h = 0;
        for (int i = 1;; i++) {

            // subtracting odd no. of ball2 , because balls are either odd or
            // even order
            ball1 -= 2 * i - 1;
            if (ball1 >= 0)
                h++;
            else
                break;
            // subtracting even no.of ball2, because balls are either odd or
            // even order
            ball2 -= 2 * i;
            if (ball2 >= 0)
                h++;
            else
                break;
        }
        return h;
    }
    int maxHeightOfTriangle(int red, int blue) {
        // just taking red and blue ball as first one by one check for maximum
        // height
        return max(maximizer(red, blue), maximizer(blue, red));
    }
};