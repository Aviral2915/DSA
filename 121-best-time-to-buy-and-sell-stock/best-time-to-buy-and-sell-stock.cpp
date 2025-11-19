class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int max_profit=0;

        for(int i=0; i<prices.size();i++){
            int p=prices[i];

            min_price=min(min_price,p);
            max_profit=max(max_profit,p-min_price);
        }
        return max_profit;
        
    }
};