class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=0;
        int sell=1;
        int profit;
        int maxProfit=0;
        while(sell<n){
            if(prices[sell]>prices[buy]){
                profit=prices[sell]-prices[buy];
                maxProfit=max(profit,maxProfit);
            }
            else{
                buy=sell;
            }
            sell++;
        }
        return maxProfit;
    }
};
