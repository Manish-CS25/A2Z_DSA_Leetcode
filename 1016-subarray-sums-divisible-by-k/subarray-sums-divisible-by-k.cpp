// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {

//         int count=0;
//         for(int i=0;i<nums.size();i++)
//         {   int sum = 0;
//             for(int j=i;j<nums.size();j++){
//               sum = sum + nums[j];
//               if(sum%k==0){
//                 count++;

//               }
//             }
//         }

//         return count;
//     }
// };

//------------Above solution is brute force solution and it gives TLE--

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // no. of count of subarray
        int count = 0;
        // To store the current prefix sum mod k
        int prefix = 0;

        // Frequency array to store counts of remainders
        vector<int> arr(k, 0);
        // Initialize with 1 to account for the subarrays that start from the
        // beginning
        arr[0] = 1;
        for (int i = 0; i < nums.size(); i++) {

            // Update prefix sum and take modulo k
            prefix = (prefix + nums[i] % k + k) % k;

            // Increment result by the frequency of the current remainder
            count += arr[prefix];

            // Increment the frequency of the current remainder
            arr[prefix]++;
        }
        return count; // Return the total count of valid subarrays
    }
};