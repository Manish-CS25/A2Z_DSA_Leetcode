class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxProfit = 0;
        int minPrice = INT_MAX;
        for (int &p : prices) {

            if (p < minPrice) {
                minPrice = p;
            }


            mxProfit = max(mxProfit, p - minPrice);
        }
        return mxProfit;
    }
};