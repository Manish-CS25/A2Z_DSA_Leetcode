class Solution {
public:
    int numberOfSteps(int num) {

        int s = 0;

        while (num) {
            s++;

            if (num % 2==0) {
                num /= 2;
            }
            
            else {
                num -= 1;
            }
            cout << num << " ";
        }

        return s;
    }
};