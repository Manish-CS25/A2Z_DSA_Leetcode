class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {

        vector<int> ans;
        for (int i = 0; i< exp.size(); i++) {

            char curr = exp[i];

            if (curr == '*' || curr == '+' || curr == '-') {
                vector<int> left, right;
                // left subtree recursion
                left = diffWaysToCompute(exp.substr(0, i));

                // right subtree recursion
                right = diffWaysToCompute(exp.substr(i + 1));

                for (auto i : left) {
                    for (auto j : right) {
                        if (curr == '*')
                            ans.push_back(i * j);
                        else if (curr == '+')
                            ans.push_back(i + j);
                        else
                            ans.push_back(i - j);
                    }
                }
            }
        }
        if (ans.empty())
            ans.push_back(stoi(exp));
        return ans;
    }
};