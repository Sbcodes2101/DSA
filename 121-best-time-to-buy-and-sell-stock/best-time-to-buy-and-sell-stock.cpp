class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MAX;
        int sell = INT_MIN;
        for(int i=0;i<n;i++){
            buy = min(buy,prices[i]);
            if(prices[i]>buy) sell = max(sell,prices[i]-buy);
        }

        return (sell==INT_MIN)? 0:sell;
    }
};