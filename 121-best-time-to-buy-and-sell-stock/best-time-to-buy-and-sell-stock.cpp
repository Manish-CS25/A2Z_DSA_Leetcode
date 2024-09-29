class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0; // Not enough prices to make a profit
        
        int minPrice = INT_MAX; // Initialize minPrice to the maximum possible value
        int maxProfit = 0; // Initialize maxProfit to 0
        
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
