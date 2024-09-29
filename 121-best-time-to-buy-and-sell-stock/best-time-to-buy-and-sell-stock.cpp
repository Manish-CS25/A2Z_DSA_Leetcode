class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0; 
        
        int minPrice = INT_MAX; 
        int maxProfit = 0; 
        
        for (int price : prices) {
            // Update minPrice if the current price is lower
            if (price < minPrice) {
                minPrice = price;
            }
            // Calculate potential profit
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit; // Return the maximum profit found
    }
};
