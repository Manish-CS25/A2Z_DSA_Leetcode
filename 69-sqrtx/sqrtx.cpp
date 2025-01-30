// class Solution {
// public:
//     int mySqrt(int x) {
//         int n = x / 2;
//         int ans = 0;
//         if(x==1 ) return x;

//         for (long long i = 1; i <= n; i++) {
//             if (i * i <= x) {
//                 ans = i;
//             }

//             else
//                 break;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x) {
                return mid;
                break;
            } else if (mid * mid < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};