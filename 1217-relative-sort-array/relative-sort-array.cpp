class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> ans2;
        // vector<int> ans3;

        int count = 0;
        for (int i = 0; i < arr2.size(); i++) {

            ans.push_back(arr2[i]);
            count = 0;
            for (int j = 0; j < arr1.size(); j++) {

                if (arr1[j] == arr2[i]) {
                    if (count)
                        ans.push_back(arr1[j]);
                    count++;
                }
            }
        }
        for (int i = 0; i < arr1.size(); i++) {

            // ans.push_back(arr2[i]);
            for (int j = 0; j < ans.size(); j++) {
                count = 0;
                if (arr1[i] == ans[j]) {

                    count++;
                    break;
                }
            }
            if (!count) {
                ans2.push_back(arr1[i]);
            }
        }
        sort(ans2.begin(), ans2.end());
        for(int i=0;i<ans2.size();i++){
            ans.push_back(ans2[i]);
        }

        return ans;
    }
};