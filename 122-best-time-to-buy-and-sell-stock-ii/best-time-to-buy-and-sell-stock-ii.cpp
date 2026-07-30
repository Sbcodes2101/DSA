class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // greedy approach will work here before, we can buy and sell unlimited times and
        // after selling a stock, i can buy the same on again
        int sum = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]<prices[i]) sum+= prices[i]-prices[i-1];
        }

        return sum;
    }
};