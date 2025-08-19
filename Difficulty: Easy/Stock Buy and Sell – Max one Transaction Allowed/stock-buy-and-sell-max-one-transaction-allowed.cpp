class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0;
        int minPrice = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
            
        }
        return maxProfit;
    }
};
