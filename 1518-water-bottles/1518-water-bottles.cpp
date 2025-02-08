class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles + (numBottles-1)/(numExchange-1);
        
        return result;
    }
};