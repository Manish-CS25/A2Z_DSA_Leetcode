// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();
//         vector<int> ans;
        
//         // Use a set to track the common elements in the current prefixes
//         unordered_set<int> setA;
//         unordered_set<int> setB;
        
//         for (int i = 0; i < n; ++i) {
//             setA.insert(A[i]);
//             setB.insert(B[i]);
            
//             // Calculate the number of common elements in both sets
//             int commonCount = 0;
//             for (int num : setA) {
//                 if (setB.find(num) != setB.end()) {
//                     ++commonCount;
//                 }
//             }
            
//             // Append the result for the current prefix
//             ans.push_back(commonCount);
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> res(n);
        vector<int> count(n+1, 0);

        int common = 0;

        for(int i=0; i<n ;i++){
            count[A[i]]++;
            if(count[A[i]]==2) common++;
            count[B[i]]++;
            if(count[B[i]]==2) common++;

            res[i] = common;

        }
        return res;
    }
};
