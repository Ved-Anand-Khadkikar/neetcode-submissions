class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=0;
        int sell=1;
        int profit=0;
        int maxProfit=0;
        while(sell<n){
            if(prices[sell]>prices[buy]){
                profit=prices[sell]-prices[buy];
            }
            else{
                buy=sell;
            }
            maxProfit=max(profit,maxProfit);
            sell++;
        }
        return maxProfit;
    }
};
