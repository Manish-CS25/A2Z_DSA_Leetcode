class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink_b = numBottles;
        int empty_b = numBottles;
        while(empty_b>=numExchange){
            int new_d =empty_b/numExchange;
            int rem_b = empty_b % numExchange;
            drink_b += new_d;
            empty_b = new_d+ rem_b;


        }
        return drink_b;
        
    }
};