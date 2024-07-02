
// ---------My approach------

// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

//         vector<int> ans;
//         int temp = 1e9;
//         int j = 0;
//         for (int i = 0; i < nums1.size(); i++) {
//             for(int j=0 ;j<nums2.size();j++){

//                 if (nums1[i] == nums2[j]) {
//                     ans.push_back(nums2[j]);
//                     nums1[i]=INT_MIN;
//                     nums2[j]=INT_MAX;
//                     break;
//                 }

//             }
//         }
//         return ans;
//     }
// };

// ==============Another Appraoch========

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        int i = 0; // nums1
        int j = 0; // nums2
        while (i < n && j < m) {
            if (nums1[i] > nums2[j]) {
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};