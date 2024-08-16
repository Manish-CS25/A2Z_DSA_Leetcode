class Solution {
    void f(int index, int k, int t, vector<vector<int>>& ans,
           vector<int>& subseq, vector<int>& arr) {

        if (t == 0 && subseq.size() == k) {
            ans.push_back(subseq);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > t || subseq.size() > k)
                break;
            subseq.push_back(arr[i]);

            f(i + 1, k, t - arr[i], ans, subseq, arr);

            subseq.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int t) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> subseq;
        f(0, k, t, ans, subseq, arr);
        return ans;
    }
};