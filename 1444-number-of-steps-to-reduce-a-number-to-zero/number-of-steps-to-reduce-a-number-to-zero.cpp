// class Solution {
// public:
//     int numberOfSteps(int num) {

//         int s = 0;

//         while (num) {
//             s++;

//             if (num % 2==0) {
//                 num /= 2;
//             }

//             else {
//                 num -= 1;
//             }

//         }

//         return s;
//     }
// };

class Solution {
public:
    int numberOfSteps(int num) {

        if (num == 0)
            return 0;

        if (num % 2 == 0)

            return 1 + numberOfSteps(num /= 2);

        return 1 + numberOfSteps(num -= 1);
    }
};